#include <gpiod.h>

#define RELAY_NUM 4
#define GPIOD_RELAY1 26
#define GPIOD_RELAY2 19
#define GPIOD_RELAY3 13
#define GPIOD_RELAY4 6

int relay_pins[4] = { GPIOD_RELAY1, GPIOD_RELAY2, GPIOD_RELAY3, GPIOD_RELAY4 }

struct gpiod_chip *chip;
struct gpiod_line *relay[RELAY_NUM];

void relay_test() {
}

void init_gpios() {
    const char *chipname = "gpiochip0";
    chip = gpiod_chip_open_by_name(chipname);
    if (!chip)
    {
        syslog(LOG_ERR, "Open chip failed\n");
        exit(0);
    }
for (short i=0; i<RELAY_NUM; i++) {
relay[i] = gpiod_chip_get_line(chip, relay_pins[i]);
}
}

void main(int argc, char* argv[]) {
}
