#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

extern bool colortoggle;
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
    chassis.setPose(-59.4, 8, 227);
    arm.set_zero_position(-70);
    fastintake.tare_position();
    arm.move_absolute(600, 200);
    delay(700);
    chassis.moveToPoint(-48, 26, 800, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    arm.move_absolute(300, 100);
    clamp.toggle();
    delay(100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-24, 24, 700, {.maxSpeed = 60});
    intake.move_voltage(12000);
    fastintake.move_voltage(10000);
    chassis.turnToHeading(45, 600, {.maxSpeed = 70});
    chassis.moveToPoint(2, 62, 1000, {.maxSpeed = 90});
    chassis.turnToHeading(260, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-44, 48, 1200, {.maxSpeed = 90});
    delay(800);
    chassis.moveToPoint(-63, 47, 900, {.maxSpeed = 55});
    chassis.turnToHeading(45, 600, {.maxSpeed = 65});
    chassis.moveToPoint(-48, 62, 900);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(-60, 60, 900, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_relative(-700, 600);
    chassis.moveToPoint(-48, 55, 600);
    chassis.turnToHeading(90, 400);
    chassis.waitUntilDone();

    int x = dist.get();
    x = x * 0.0414772 + 5.75;
    chassis.setPose(-48, 71.5 - x, 90);
    delay(50);
    chassis.turnToHeading(180, 700);
    chassis.moveToPoint(-48, -6, 1000, {.maxSpeed = 80});
    chassis.turnToHeading(0, 900, {.maxSpeed = 70});
    chassis.waitUntilDone();
    delay(150);
    x = dist.get();
    x = x * 0.0414772 + 5.75;
    chassis.setPose(-71.5 + x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);

    chassis.moveToPoint(-48, -26, 1300, {.forwards = false, .maxSpeed = 80});

    chassis.waitUntilDone();
    clamp.toggle();
    chassis.turnToHeading(90, 800, {.maxSpeed = 50});
    chassis.moveToPoint(-24, -24, 800, {.maxSpeed = 60});
    intake.move_voltage(12000);
    fastintake.move_voltage(10000);
    chassis.turnToHeading(100, 600, {.maxSpeed = 70});
    chassis.moveToPoint(0, -62, 1200,{.maxSpeed=90});
    chassis.turnToHeading(270, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-44, -48, 1200, {.maxSpeed = 90});
    delay(500);
    chassis.moveToPoint(-58, -47, 1000, {.maxSpeed = 55});
    chassis.turnToHeading(135, -600, {.maxSpeed = 85});
    chassis.moveToPoint(-48, -64, 1100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 75});
    chassis.moveToPoint(-61, -64, 1000, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();

    fastintake.move_relative(-700, 600);
    chassis.moveToPoint(20, -48, 1300);
    arm.move_absolute(75, 200);
    chassis.moveToPoint(30, -10, 1000, {.maxSpeed = 70});
    chassis.moveToPoint(77, -6, 1100, {.maxSpeed = 80});
    intake.move_voltage(0);
    chassis.turnToHeading(180, 800, {.maxSpeed = 70});
    chassis.waitUntilDone();
    x = dist.get();
    x = x * 0.0414772 + 5.75;
    chassis.setPose(71.5 - x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);
    chassis.turnToHeading(140,700);
    chassis.moveToPoint(75, -70, 1900, {.maxSpeed = 90});
    chassis.moveToPoint(50, 0, 1000, {.forwards = false});
    chassis.moveToPoint(50, 7, 700, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.moveToPoint(58, -3, 1000);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(65, -3, 1000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    chassis.setPose(62, 0, 90);
    delay(50);
    chassis.moveToPoint(52, 0, 800, {.forwards = false});
    fastintake.move_relative(-100, 600);
    arm.move_absolute(600, 150);
    chassis.waitUntilDone();
    delay(600);
    chassis.moveToPoint(60, 6, 700, {.forwards = false});
    chassis.turnToPoint(24, -24, 800);
    intake.move_voltage(12000);
    fastintake.move_voltage(12000);
    arm.move_absolute(750, 200);
    chassis.moveToPoint(24, -24, 800);
    chassis.turnToHeading(-45, 700, {.maxSpeed = 80});
    colortoggle = true;
    delay(500);
    chassis.moveToPoint(3, 3, 800);
    delay(500);
    chassis.turnToHeading(45, 700, {.maxSpeed = 80});
    chassis.moveToPoint(24, 24, 800);
    chassis.moveToPoint(24, 48, 800);
    chassis.turnToHeading(90, 700);
    chassis.moveToPoint(48, 50, 900);
    chassis.moveToPoint(63, 46, 900);
    chassis.turnToHeading(180, 700);
    chassis.moveToPoint(62, 62, 700, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    /*
    chassis.waitUntilDone();
    chassis.setPose(0,63,0);

    intake.move_voltage(-12000);
    chassis.moveToPoint(0,48,600,{.forwards=false,.maxSpeed=70});
    chassis.turnToHeading(135,800,{.maxSpeed=50});
    chassis.moveToPoint(38,12,1200,{.maxSpeed=80});
    chassis.waitUntil(20);
    fastintake.move_voltage(0);
    chassis.moveToPoint(48,-1,1200,{.maxSpeed=80});
    chassis.turnToHeading(270,700,{.maxSpeed=50});
    chassis.moveToPoint(66,1,1000,{.forwards=false,.maxSpeed=70});
    chassis.turnToHeading(270,900);
    chassis.waitUntilDone();
    chassis.setPose(63,0,270);
    fastintake.move_voltage(-10000);
    delay(800);
    chassis.turnToHeading(0,800,{.maxSpeed=80});
    chassis.moveToPoint(64,62,3000,{.maxSpeed=80});
    chassis.moveToPoint(60,0,1200,{.forwards=false,.maxSpeed=80});
    chassis.turnToHeading(180,800,{.maxSpeed=60});
    chassis.moveToPoint(64,-62,3000,{.maxSpeed=80});



    /* chassis.turnToHeading(-45,800,{.maxSpeed=50});
    chassis.moveToPose(45,45,-45,1200,{.forwards=false});
    chassis.waitUntilDone();
    clamp.toggle();
    chassis.moveToPoint(24,48,1200,{.maxSpeed=70});
    fastintake.move_voltage(-9000);
    chassis.turnToHeading(75,700,{.maxSpeed=50});
    chassis.moveToPoint(48,60,800,{.maxSpeed=60});
    chassis.turnToHeading(260,800,{.maxSpeed=50});
    intake.move_voltage(7000);
    chassis.moveToPoint(60,60,900,{.forwards=false,.maxSpeed=70});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_voltage(0);
    chassis.moveToPoint(36,20,800,{.maxSpeed=50});
    chassis.moveToPoint(60,0,1000,{.maxSpeed=50});
    chassis.moveToPoint(60,-60,1500,{.maxSpeed=50}); */
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