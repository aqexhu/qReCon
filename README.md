# AQEX qReCon superior quality 4 channel relay module in a Raspberry Pi HAT form factor
## Software guard for safe shutdown of the Raspberry PI
![alt text](https://github.com/aqexhu/qReCon/blob/main/Pictures/qReCon_trans_small_v1.png?raw=true)

## 1. Greeting / purpose

First of all, we would like to express our deeply honest greeting to all of you, who lay trust in our efforts and use our products! We are working hard day-by-day to keep software and hardware up-to-date and develop the products and ourselves. We are trying to deliver devices and services, which serve your lives and purposes better, than any past ones, taking our environment also in focus. Sustainable, long lifespan, reliable, flexible and easy to use - in a green shape!

## 2. Device

The qReCon superior quality 4 channel relay module was created, because the mission critical endpoints need reliable and durable control over the connected devices. The qReCon features high-end austrian SCHRACK relays guaranteed for 250VAC@10A high lifespan, with galvanic isolation and top quality screw terminals for easy deployment and managability. On top of that, the Raspberry Pi HAT module form factor delivers easy, plug-and-play installation without efforts.
Our solution is simple in design with robust build and very good support.

## 3. Installation

### 3.1 RaspiOS on Raspberry PI binary

If you are using RaspiOS, you can clone the repository and start the compiled binaries, run the shell script or execute python3 interpreter. The binaries and the source codes for the c++ version are available for distribution. Feel free to post pull requests!

### 3.2 RaspiOS on Raspberry PI compile from source

Libraries needed:
```
libgpiod-dev
```

You can compile the source files with following options and libraries:
```
/usr/bin/gcc -g -Wall relay_test.cpp -o relay_test -lgpiod
```

## 4. Usage

```
/home/pi/qReCon/relay_test
```
