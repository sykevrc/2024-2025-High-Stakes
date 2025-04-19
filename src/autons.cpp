#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"
void redRush()
{
    chassis.setPose(-55, 16, 180);
    fastintake.tare_position();
    chassis.turnToPoint(-48, 0, 500);
    chassis.moveToPoint(-50, 2, 600);
    intake.move_voltage(-12000);

    chassis.waitUntil(5);
    arm.move_absolute(1000, 200);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-63, -1, 700, {.forwards = false});
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    fastintake.move_absolute(-700, 530);
    delay(300);
    chassis.moveToPoint(-50, 25, 800);
    chassis.turnToHeading(270, 700);
    chassis.moveToPose(-25, 25, 270, 1300, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.turnToHeading(0, 500);
    fastintake.move_voltage(-9000);
    chassis.moveToPoint(-24, 48, 900);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-8, 44, 800, {.maxSpeed = 70});
    chassis.moveToPoint(-20, 44, 900, {.forwards = false});
    chassis.turnToHeading(45, 500);
    chassis.moveToPose(-6.5, 54, 90, 1300);
    delay(500);
    chassis.moveToPoint(-12, 12, 1000, {.forwards = false});
    /*chassis.turnToPoint(-7,36,900,{.maxSpeed=70});
    fastintake.move_voltage(-9000);
    chassis.moveToPoint(-8,34,800);
    chassis.turnToHeading(0,600);
    chassis.moveToPose(-8,60,0,1000);
    chassis.turnToHeading(270,700);
    chassis.moveToPoint(-24,48,800);*/
}
void blueRush()
{
    chassis.setPose(55, 16, 180);
    fastintake.tare_position();
    chassis.turnToPoint(48, 0, 500);
    chassis.moveToPoint(50, 2, 600);
    intake.move_voltage(-12000);

    chassis.waitUntil(5);
    arm.move_absolute(1000, 200);
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(63, -1, 700, {.forwards = false});
    chassis.turnToHeading(270, 600);
    chassis.waitUntilDone();
    fastintake.move_absolute(-700, 530);
    delay(300);
    chassis.moveToPoint(50, 23, 800);
    chassis.turnToHeading(90, 700);
    chassis.moveToPose(25, 25, 90, 1300, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.turnToHeading(0, 500);
    fastintake.move_voltage(-9000);
    chassis.moveToPoint(24, 48, 900);
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(8, 44, 800, {.maxSpeed = 70});
    chassis.moveToPoint(20, 44, 900, {.forwards = false});
    chassis.turnToHeading(-45, 500);
    chassis.moveToPose(7, 54, 90, 1300);
    delay(500);
    chassis.moveToPoint(12, 12, 1000, {.forwards = false});
};
void skills()
{
    extern bool a;
    a = true;
    chassis.setPose(-59.4, 8, 230);
    arm.set_zero_position(-75);
    fastintake.tare_position();
    arm.move_absolute(600, 200);
    delay(700);
    chassis.moveToPoint(-48, 26, 800, {.forwards = false, .maxSpeed = 80});
    arm.move_absolute(75, 100);
    chassis.waitUntilDone();
    clamp.toggle();
    delay(100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-24, 24, 700, {.maxSpeed = 60});
    intake.move_voltage(12000);
    fastintake.move_voltage(12000);

    chassis.turnToHeading(45, 600, {.maxSpeed = 70});
    chassis.moveToPoint(2, 55, 1300, {.maxSpeed = 90});
    chassis.turnToHeading(0, 600);
    chassis.moveToPoint(2, 71, 1200, {.maxSpeed = 80});
    chassis.waitUntil(5);
    fastintake.move_relative(-100, 600);
    arm.move_absolute(550, 200);
    chassis.cancelAllMotions();
    chassis.moveToPoint(2, chassis.getPose().y-2, 800,{.forwards=false});
    intake.move_voltage(0);
    chassis.turnToHeading(0, 600);
    chassis.moveToPoint(2,70, 800, {.maxSpeed=80});
    chassis.moveToPoint(2, chassis.getPose().y-2, 800,{.forwards=false});
    intake.move_voltage(0);
    chassis.turnToHeading(0, 200);
    chassis.moveToPoint(2,70, 800, {.maxSpeed=80});
    arm.move_relative(100,200);
    fastintake.move_voltage(10000);
    chassis.waitUntilDone();
    delay(50);
    chassis.setPose(0, 62, chassis.getPose().theta);
    chassis.moveToPoint(0, 50, 900, {.forwards = false});
    arm.move_absolute(300, 200);
    chassis.turnToHeading(280, 600, {.maxSpeed = 50});
    chassis.moveToPoint(-42, 51, 1200, {.maxSpeed = 90});
    intake.move_voltage(12000);
    delay(800);
    chassis.moveToPoint(-61, 47, 900, {.maxSpeed = 55});
    chassis.turnToHeading(45, 600, {.maxSpeed = 65});
    chassis.moveToPoint(-47, 62, 900);
    chassis.turnToHeading(120, 600,{.maxSpeed=60});
    chassis.moveToPoint(-60, 60, 900, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_relative(-700, 600);

    chassis.moveToPoint(-55, 6, 1700, {.maxSpeed = 90});
    chassis.turnToHeading(0, 1000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    delay(150);
    int x = dist.get();
    x = x * 0.0413 + 5.75;
    chassis.setPose(-71.5 + x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);


    chassis.moveToPoint(-48, -26, 1300, {.forwards = false, .maxSpeed = 80});

    chassis.waitUntilDone();
    clamp.toggle();
    delay(100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    arm.move_absolute(85,200);
    chassis.moveToPoint(-24, -24, 700, {.maxSpeed = 60});
    intake.move_voltage(12000);
    fastintake.move_voltage(12000);

    chassis.turnToHeading(135, 600, {.maxSpeed = 70});
    chassis.moveToPoint(-1.5, -55, 1300, {.maxSpeed = 90});
    chassis.turnToHeading(180, 600);
    chassis.moveToPoint(-1.5, -73, 1200, {.maxSpeed = 80});
    chassis.waitUntil(5);
    fastintake.move_relative(-100, 600);
    arm.move_absolute(550, 200);
    chassis.cancelAllMotions();
    chassis.moveToPoint(-1.5, chassis.getPose().y+3, 800,{.forwards=false});
    intake.move_voltage(0);
    chassis.moveToPoint(-1.5,-70, 800, {.maxSpeed=80});
    arm.move_relative(100,200);
    fastintake.move_voltage(10000);
    chassis.waitUntilDone();
    delay(50);
    chassis.setPose(0, -62, chassis.getPose().theta);
    chassis.moveToPoint(0, -50, 900, {.forwards = false});
    arm.move_absolute(300, 200);
    intake.move_voltage(12000);
    chassis.turnToHeading(250, 600, {.maxSpeed = 50});
    chassis.moveToPoint(-42, -51, 1200, {.maxSpeed = 90});
    delay(800);
    chassis.moveToPoint(-61, -47, 900, {.maxSpeed = 55});
    chassis.turnToHeading(135, 600, {.maxSpeed = 65});
    chassis.moveToPoint(-47, -62, 900);
    chassis.turnToHeading(30, 700,{.maxSpeed=60});
    chassis.moveToPoint(-60, -60, 900, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_relative(-700, 600);

    delay(150);
    chassis.moveToPoint(22, -52, 1600);
    arm.move_absolute(75, 200);
    chassis.turnToHeading(-90, 1000, {.maxSpeed = 70});

    chassis.waitUntilDone();
    delay(150);
    x = dist.get();
    x = x * 0.0414772 + 5.75;
    chassis.setPose(chassis.getPose().x,-71.5+x, chassis.getPose().theta);
    delay(50);
    chassis.turnToPoint(0,-96,800,{.maxSpeed=90});
    fastintake.move_voltage(12000);
    arm.move_absolute(90,200);
    chassis.moveToPoint(48,0,2000,{.forwards=false});
    clamp.toggle();
    chassis.turnToHeading(90,800,{.maxSpeed=80});
    chassis.moveToPoint(67,0,800,{.maxSpeed=70});
    chassis.waitUntilDone();
    delay(50);
    chassis.setPose(63,0,chassis.getPose().theta);
    chassis.moveToPoint(58,0,800,{.forwards=false});
    arm.move_absolute(600,200);
    chassis.moveToPoint(50,0,800,{.forwards=false});
    arm.move_absolute(300,200);
    chassis.turnToHeading(-45,800,{.maxSpeed=60});
    chassis.moveToPoint(24,24,900,{.maxSpeed=90});
    chassis.moveToPoint(24,28,900,{.maxSpeed=90});
    chassis.turnToHeading(100,800,{.maxSpeed=90});
    /*
    fastintake.move_voltage(10000);
    chassis.moveToPoint(48, -17, 1800);
    chassis.turnToHeading(180, 1000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    delay(150);
    x = dist.get();
    x = x * 0.0414772 + 5.75;
    chassis.setPose(71.5 - x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);
    chassis.moveToPoint(47, 5, 900, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.moveToPoint(58, 1, 1000);
    chassis.moveToPoint(67, 1, 1000, {.maxSpeed = 70});
    chassis.turnToHeading(90, 900);
    chassis.waitUntilDone();
    chassis.setPose(62, 0, 90);
    delay(50);
    chassis.moveToPoint(55, 0, 800, {.forwards = false});
    chassis.turnToHeading(90, 900);
    fastintake.move_relative(-100, 600);
    arm.move_absolute(600, 150);
    chassis.waitUntilDone();
    delay(600);
    chassis.moveToPoint(50, 0, 700, {.forwards = false});
    chassis.turnToPoint(24, 48, 800);
    intake.move_voltage(12000);
    fastintake.move_voltage(10000);
    arm.move_absolute(750, 200);
    chassis.moveToPoint(24, 48, 1000);
    chassis.turnToHeading(180, 900, {.maxSpeed = 60});
    chassis.moveToPoint(20, 24, 800);
    chassis.turnToHeading(225, 900, {.maxSpeed = 60});
    delay(500);
    chassis.moveToPoint(0, -3, 800);
    fastintake.move_voltage(0);

    chassis.turnToHeading(135, 700, {.maxSpeed = 80});

    chassis.moveToPoint(24, -24, 800);
    chassis.moveToPoint(60,-48,1200);
    fastintake.move_voltage(10000);
    chassis.turnToHeading(225, 700);
    chassis.moveToPoint(48, -64, 1000);
    chassis.turnToHeading(315, 700);
    chassis.moveToPoint(61, -64, 1000,{.forwards=false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.moveToPoint(45,-48,-1000);
    chassis.moveToPoint(38,0,1000);
    chassis.moveToPoint(62,70,2000,{.maxSpeed=80});
    chassis.moveToPoint(0,0,2000,{.forwards=false, .maxSpeed=80});
    
    /**/
    a = false;
}
void elimRed() {};
void elimBlue() {};
void redSoloWP()
{
    chassis.setPose(-55, 16, 180);
    fastintake.tare_position();
    chassis.turnToPoint(-48, 0, 600, {.maxSpeed = 55});
    chassis.moveToPoint(-50, 2, 800, {.maxSpeed = 55});
    intake.move_voltage(-12000);

    chassis.waitUntil(5);
    arm.move_absolute(1000, 200);
    chassis.turnToHeading(90, 800, {.maxSpeed = 55});
    chassis.moveToPoint(-63, -1, 700, {.forwards = false});
    chassis.turnToHeading(90, 900);
    chassis.waitUntilDone();
    fastintake.move_absolute(-700, 530);
    delay(300);
    chassis.moveToPoint(-50, 25, 800);
    chassis.turnToHeading(270, 700);
    chassis.moveToPose(-25, 25, 270, 1300, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.turnToHeading(0, 500);
    fastintake.move_voltage(-9000);
    chassis.moveToPoint(-24, 48, 2200);
    chassis.moveToPoint(-12, 12, 800, {.forwards = false});
    chassis.waitUntilDone();
    arm.move_absolute(500, 200);
};
void blueSoloWP()
{
    chassis.setPose(55, 16, 180);
    fastintake.tare_position();
    chassis.turnToPoint(48, 0, 600, {.maxSpeed = 55});
    chassis.moveToPoint(50, 2, 800, {.maxSpeed = 55});
    intake.move_voltage(-12000);

    chassis.waitUntil(5);
    arm.move_absolute(1000, 200);
    chassis.turnToHeading(270, 800, {.maxSpeed = 55});
    chassis.moveToPoint(63, -1, 700, {.forwards = false});
    chassis.turnToHeading(270, 900);
    chassis.waitUntilDone();
    fastintake.move_absolute(-700, 530);
    delay(300);
    chassis.moveToPoint(50, 25, 800);
    chassis.turnToHeading(90, 700);
    chassis.moveToPose(25, 25, 90, 1300, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.turnToHeading(0, 500);
    fastintake.move_voltage(-9000);
    chassis.moveToPoint(24, 48, 2200);
    chassis.moveToPoint(12, 12, 800, {.forwards = false});
    chassis.waitUntilDone();
    arm.move_absolute(500, 200);
};

void skills1()
{
    chassis.setPose(0, 0, 0);
    chassis.turnToPoint(60, 0, 2500, {.maxSpeed = 80});
}