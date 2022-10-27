#include <gpiod.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#define RELAY_NUM 4
#define GPIOD_B1_RELAY1 21
#define GPIOD_B1_RELAY2 20
#define GPIOD_B1_RELAY3 16
#define GPIOD_B1_RELAY4 5
#define GPIOD_B2_RELAY1 26
#define GPIOD_B2_RELAY2 19
#define GPIOD_B2_RELAY3 13
#define GPIOD_B2_RELAY4 6

int relay_pins[8] = {GPIOD_B1_RELAY1, GPIOD_B1_RELAY2, GPIOD_B1_RELAY3, GPIOD_B1_RELAY4, GPIOD_B2_RELAY1, GPIOD_B2_RELAY2, GPIOD_B2_RELAY3, GPIOD_B2_RELAY4};

struct gpiod_chip *chip;
struct gpiod_line *relay[RELAY_NUM];

void delay(int del_ms)
{
    clock_t start = clock();
    while (clock() < start + del_ms*1000)
        ;
}

void relay_test()
{
    for (short i = 0; i < RELAY_NUM; i++)
    {
        gpiod_line_set_value(relay[i], 1);
        delay(2000);
        gpiod_line_set_value(relay[i], 0);
    }
}

void deinit_gpios()
{
    for (short i = 0; i < RELAY_NUM; i++)
    {
        gpiod_line_release(relay[i]);
    }
    gpiod_chip_close(chip);
}

void init_gpios()
{
    const char *chipname = "gpiochip0";
    chip = gpiod_chip_open_by_name(chipname);
    printf("Chip name: %s - label: %s - %d lines\n", gpiod_chip_name(chip), gpiod_chip_label(chip), gpiod_chip_num_lines(chip));
    if (!chip)
    {
        perror("Open chip failed\n");
        exit(0);
    }
    for (short i = 0; i < RELAY_NUM; i++)
    {
        relay[i] = gpiod_chip_get_line(chip, relay_pins[i]);
        gpiod_line_request_output(relay[i], "Relay_test", 0);
    }
}

int main(int argc, char *argv[])
{
    init_gpios();
    relay_test();
    deinit_gpios();
    return 0;
}
