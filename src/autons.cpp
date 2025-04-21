#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"
void RLE()
{
    pros::Task([]{
        colorsens.set_led_pwm(100);
        
        while (true) {
                if(fastintake.get_actual_velocity() >=500 && colorsens.get_hue() > 200 &&colorsens.get_hue()<260){
                    while (line.get_value()>2700){
                        fastintake.move_voltage(10000);
                    }
                    Task::delay(75);
                    fastintake.move_velocity(0);
                    Task::delay(250);
                    fastintake.move_voltage(10000);
                }
            Task::delay(10);
    }});
    chassis.setPose(-49,32,73.12);
    arm.move_absolute(300,200);
    intake.move_voltage(12000);
    chassis.moveToPoint(-24,44,1400,{.minSpeed=50});
    delay(500);
    chassis.turnToHeading(0,600);
    chassis.moveToPoint(-23,25,900,{.forwards=false});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_voltage(10000);
    chassis.turnToHeading(45,400);
    chassis.moveToPoint(-18,45,1700,{.minSpeed=50});
    doink.toggle();
    chassis.turnToHeading(90,700);
    chassis.moveToPoint(-8,46,800);
    delay(500);
    
    chassis.moveToPoint(-29,53,1400,{.forwards=false,.minSpeed=50});
    chassis.turnToHeading(300,900,{.maxSpeed=70});
    chassis.turnToHeading(280,200);
    doink.toggle();
    chassis.moveToPoint(-56,64,1000);
    doink.toggle();
    chassis.moveToPose(-56,59,400,1300,{.forwards=false, .minSpeed=30});
    
    /**/
}
void RRE()
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
void BLE() {};
void BRE() {};

bool a = true;

void skills()
{
    pros::Task([]
               {
        while(a = true){
            if(fastintake.get_actual_velocity()==0&&(arm.get_position()<60||arm.get_position()>90)){
                fastintake.move_voltage(-2000);
                Task::delay(300);
                fastintake.move_voltage(10000);
            }
        } });

    chassis.setPose(-59.4, 8, 230);
    arm.set_zero_position(-67);
    fastintake.tare_position();
    arm.move_absolute(600, 200);
    delay(700);
    chassis.moveToPoint(-48, 26, 800, {.forwards = false, .maxSpeed = 80});
    arm.move_absolute(75, 100);
    chassis.waitUntilDone();
    clamp.toggle();
    delay(100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-24, 24, 900, {.maxSpeed = 60, .minSpeed = 10});
    intake.move_voltage(12000);
    fastintake.move_voltage(12000);

    chassis.turnToHeading(45, 600, {.maxSpeed = 70, .minSpeed = 10});
    chassis.moveToPoint(0.5, 55, 1300, {.maxSpeed = 90, .minSpeed = 10});
    chassis.turnToHeading(0, 600);
    chassis.moveToPoint(0.5, 71, 800, {.maxSpeed = 80, .minSpeed = 10});
    chassis.waitUntil(5);
    fastintake.move_relative(-100, 600);
    arm.move_absolute(550, 200);
    chassis.cancelAllMotions();
    chassis.moveToPoint(1, chassis.getPose().y - 2, 500, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(0, 300);
    chassis.moveToPoint(1, 70, 500, {.maxSpeed = 80, .minSpeed = 10});
    arm.move_relative(100, 200);
    chassis.moveToPoint(0, chassis.getPose().y - 2, 500, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(0, 300);
    chassis.moveToPoint(0, 70, 500, {.maxSpeed = 80, .minSpeed = 10});
    arm.move_relative(100, 200);
    fastintake.move_voltage(10000);
    chassis.waitUntilDone();

    delay(50);
    chassis.setPose(0, 63, chassis.getPose().theta);
    chassis.moveToPoint(0, 50, 900, {.forwards = false, .minSpeed = 10});
    fastintake.move_voltage(10000);
    arm.move_absolute(300, 200);
    chassis.turnToHeading(270, 600, {.maxSpeed = 50, .minSpeed = 10});
    chassis.moveToPoint(-42, 48, 1300, {.maxSpeed = 80, .minSpeed = 10});
    intake.move_voltage(12000);
    delay(800);
    chassis.moveToPoint(-61, 48, 900, {.maxSpeed = 55, .minSpeed = 10});
    chassis.turnToHeading(45, 800, {.maxSpeed = 50, .minSpeed = 10});
    chassis.moveToPoint(-47, 62, 900);
    chassis.turnToHeading(100, 600, {.maxSpeed = 55});
    chassis.moveToPoint(-60, 63, 900, {.forwards = false, .minSpeed = 10});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_relative(-700, 600);

    chassis.moveToPoint(-55, 6, 1700, {.maxSpeed = 90, .minSpeed = 10});
    chassis.turnToHeading(0, 1000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    delay(150);
    int x = dist.get();
    x = x * 0.0413 + 5.75;
    chassis.setPose(-71.5 + x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);

    chassis.moveToPoint(-48, -26, 1100, {.forwards = false, .maxSpeed = 80});

    chassis.waitUntilDone();
    arm.move_absolute(76, 100);
    clamp.toggle();
    delay(100);
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    chassis.moveToPoint(-24, -24, 900, {.maxSpeed = 60, .minSpeed = 10});
    intake.move_voltage(12000);
    fastintake.move_voltage(12000);

    chassis.turnToHeading(135, 600, {.maxSpeed = 70, .minSpeed = 10});
    chassis.moveToPoint(-2, -55, 1300, {.maxSpeed = 90, .minSpeed = 10});

    chassis.turnToHeading(180, 600);
    chassis.moveToPoint(-2, -71, 600, {.maxSpeed = 80, .minSpeed = 10});
    chassis.waitUntil(5);
    fastintake.move_relative(-100, 600);
    arm.move_absolute(450, 200);
    chassis.cancelAllMotions();
    chassis.moveToPoint(-1.5, chassis.getPose().y + 2, 500, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(180, 300);
    chassis.moveToPoint(-1.5, -70, 500, {.maxSpeed = 80, .minSpeed = 10});
    chassis.moveToPoint(-2.5, chassis.getPose().y + 2, 500, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(180, 300);
    chassis.moveToPoint(-2.5, -70, 800, {.maxSpeed = 80, .minSpeed = 10});
    arm.move_relative(100, 200);
    fastintake.move_voltage(10000);
    chassis.waitUntilDone();

    delay(50);
    chassis.setPose(0, -63, chassis.getPose().theta);
    chassis.moveToPoint(0, -50, 900, {.forwards = false, .minSpeed = 10});
    arm.move_absolute(300, 200);
    fastintake.move_voltage(10000);
    intake.move_voltage(12000);
    chassis.turnToHeading(270, 600, {.maxSpeed = 50, .minSpeed = 10});
    chassis.moveToPoint(-42, -48, 1300, {.maxSpeed = 70, .minSpeed = 10});
    delay(800);
    chassis.moveToPoint(-62, -48, 900, {.maxSpeed = 55, .minSpeed = 10});
    chassis.turnToHeading(135, 800, {.maxSpeed = 50});
    chassis.moveToPoint(-47, -62, 900);
    chassis.turnToHeading(90, 900, {.maxSpeed = 60});

    chassis.moveToPoint(-60, -63, 900, {.forwards = false, .minSpeed = 10});
    chassis.waitUntilDone();
    clamp.toggle();
    fastintake.move_relative(-700, 600);

    delay(150);
    chassis.moveToPoint(25, -54, 1600, {.minSpeed = 10});
    fastintake.move_voltage(12000);
    arm.move_absolute(75, 200);
    chassis.turnToHeading(-90, 1000, {.maxSpeed = 70});

    chassis.waitUntilDone();
    delay(150);
    x = dist.get();
    x = x * 0.04144 + 5.75;
    chassis.setPose(chassis.getPose().x, -71.5 + x, chassis.getPose().theta);
    delay(50);
    chassis.turnToHeading(0, 800, {.maxSpeed = 60, .minSpeed = 20});

    chassis.moveToPoint(24, -30, 800);

    chassis.moveToPoint(32, -22, 600, {.minSpeed = 20});
    chassis.turnToHeading(210, 900, {.maxSpeed = 60});
    chassis.moveToPoint(52, 6, 1000, {.forwards = false, .maxSpeed = 80});

    chassis.waitUntilDone();
    clamp.toggle();
    delay(50);
    // chassis.swingToHeading(120,DriveSide::LEFT,900);
    chassis.moveToPoint(67, 0, 1000, {.maxSpeed = 70, .minSpeed = 10});
    chassis.turnToHeading(90, 800, {.maxSpeed = 80});

    chassis.waitUntilDone();
    delay(50);
    chassis.setPose(63, 0, chassis.getPose().theta);
    chassis.moveToPoint(56.5, 0, 800, {.forwards = false});
    chassis.turnToPoint(63, 0, 300);

    fastintake.move_relative(-100, 600);
    arm.move_absolute(650, 200);
    delay(500);
    chassis.moveToPoint(50, 0, 800, {.forwards = false, .minSpeed = 10});

    arm.move_absolute(300, 200);
    fastintake.move_voltage(10000);
    chassis.turnToHeading(-45, 800, {.maxSpeed = 60, .minSpeed = 10});
    chassis.moveToPoint(24, 24, 1200, {.maxSpeed = 90, .minSpeed = 10});
    chassis.moveToPoint(24, 50, 1200, {.maxSpeed = 90, .minSpeed = 10});
    chassis.turnToHeading(100, 800, {.maxSpeed = 90, .minSpeed = 10});
    chassis.moveToPoint(48, 45, 900);
    delay(500);
    chassis.moveToPoint(62, 48, 1000);
    chassis.turnToHeading(135, 800, {.minSpeed = 10});
    chassis.moveToPoint(60, 60, 900, {.forwards = false});
    chassis.waitUntilDone();
    fastintake.move_relative(-700, 600);
    clamp.toggle();
    chassis.moveToPoint(56, 56, 400);
    chassis.moveToPoint(60, 60, 500, {.forwards = false});

    fastintake.move_relative(-700, 600);
    intake.move_voltage(-2000);
    chassis.moveToPoint(40, 25, 1000, {.minSpeed = 60, .earlyExitRange = 4});
    fastintake.move_voltage(5000);
    chassis.moveToPoint(54, -3, 1000, {.minSpeed = 60, .earlyExitRange = 9});

    chassis.moveToPoint(64, -63, 2500, {.maxSpeed = 110});
    chassis.waitUntilDone();
    chassis.swingToHeading(135, DriveSide::RIGHT, 800, {.minSpeed = 90});
    chassis.moveToPoint(0, 0, 1200, {.forwards = false, .minSpeed = 40});
    chassis.waitUntil(33);
    chassis.cancelAllMotions();
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 70, .minSpeed = 40});
    a = false;
    /**/
}

void RWP()
{
    pros::Task([]{
        colorsens.set_led_pwm(100);
        
        while (true) {
                if(fastintake.get_actual_velocity() >=500 && colorsens.get_hue() > 200 &&colorsens.get_hue()<260){
                    while (line.get_value()>2700){
                        fastintake.move_voltage(10000);
                    }
                    Task::delay(50);
                    fastintake.move_velocity(0);
                    Task::delay(250);
                    fastintake.move_voltage(10000);
                }
            Task::delay(10);
    }});
    chassis.setPose(-58.42, 13.56, 225.64);
    fastintake.tare_position();
    arm.set_zero_position(-75);
    chassis.moveToPose(-59, 8, 225, 700, {.minSpeed = 30});
    delay(60);
    arm.move_absolute(600, 200);
    delay(300);
    chassis.moveToPoint(-24, 26, 1200, {.forwards = false,.maxSpeed=90, .minSpeed = 30});
    arm.move_absolute(300, 100);
    chassis.waitUntilDone();
    clamp.toggle();
    delay(60);
    chassis.turnToHeading(0, 700, {.maxSpeed = 70, .minSpeed = 30});
    fastintake.move_voltage(10000);
    intake.move_voltage(12000);
    chassis.moveToPoint(-24, 46, 600);
    chassis.turnToHeading(90, 600, {.maxSpeed = 70});
    chassis.waitUntilDone();
    int x = dist.get();
    x = x * 0.0413 + 5.75;
    chassis.setPose(chassis.getPose().x, 71.5 - x, chassis.getPose().theta);
    delay(50);
    chassis.moveToPoint(-8.5, 45, 1100, {.earlyExitRange = 2});
    chassis.moveToPoint(-49, 17, 1600, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(180, 700, {.maxSpeed = 70, .minSpeed = 30});
    chassis.moveToPoint(-49, -27, 1000, {.maxSpeed = 90});
    clamp.toggle();
    chassis.turnToHeading(-90, 600, {.maxSpeed = 60});
    fastintake.move_relative(600,600);
    chassis.moveToPoint(-24, -26, 900, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    delay(50);
    fastintake.move_voltage(10000);
    chassis.moveToPoint(-24, -55, 1100,{.minSpeed=50});
    fastintake.move_voltage(10000);
    chassis.turnToHeading(30, 700);
    chassis.moveToPoint(-20, -23, 1000,{.maxSpeed=80});
    chassis.waitUntilDone();
    arm.move_relative(150, 200);
};
void BWP() {
    pros::Task([]{
        colorsens.set_led_pwm(100);
        
        while (true) {
                if(fastintake.get_actual_velocity() >=500 && colorsens.get_hue() > 0 &&colorsens.get_hue()<8){
                    while (line.get_value()>2700){
                        fastintake.move_voltage(10000);
                    }
                    Task::delay(50);
                    fastintake.move_velocity(0);
                    Task::delay(250);
                    fastintake.move_voltage(10000);
                }
            Task::delay(10);
    }});
    chassis.setPose(58.42, 13.56, 135.64);
    fastintake.tare_position();
    arm.set_zero_position(-75);
    chassis.moveToPose(59, 8, 135, 700, {.minSpeed = 30});
    delay(60);
    arm.move_absolute(600, 200);
    delay(300);
    chassis.moveToPoint(24, 26, 1200, {.forwards = false,.maxSpeed=90, .minSpeed = 30});
    arm.move_absolute(300, 100);
    chassis.waitUntilDone();
    clamp.toggle();
    delay(60);
    chassis.turnToHeading(0, 700, {.maxSpeed = 70, .minSpeed = 30});
    fastintake.move_voltage(10000);
    intake.move_voltage(12000);
    chassis.moveToPoint(24, 46, 600);
    chassis.turnToHeading(270, 600, {.maxSpeed = 70});
    
    chassis.moveToPoint(8.5, 45, 1100, {.earlyExitRange = 2});
    chassis.moveToPoint(49, 17, 1600, {.forwards = false, .minSpeed = 10});
    chassis.turnToHeading(180, 700, {.maxSpeed = 70, .minSpeed = 30});
    chassis.waitUntilDone();
    int x = dist.get();
    x = x * 0.0413 + 5.75;
    chassis.setPose(71.5 - x, chassis.getPose().y, chassis.getPose().theta);
    delay(50);
    chassis.moveToPoint(49, -27, 1000, {.maxSpeed = 90});
    clamp.toggle();
    chassis.turnToHeading(90, 600, {.maxSpeed = 60});
    fastintake.move_relative(600,600);
    chassis.moveToPoint(24, -26, 900, {.forwards = false});
    chassis.waitUntilDone();
    clamp.toggle();
    delay(50);
    fastintake.move_voltage(10000);
    chassis.moveToPoint(24, -55, 1100,{.minSpeed=50});
    fastintake.move_voltage(10000);
    chassis.turnToHeading(-30, 700);
    chassis.moveToPoint(20, -23, 1000,{.maxSpeed=80});
    chassis.waitUntilDone();
    arm.move_relative(150, 200);
};
