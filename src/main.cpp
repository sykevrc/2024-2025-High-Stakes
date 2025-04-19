#include "main.h"
#include "robodash/api.h"

rd::Selector selector({
    {"Red Solo Winpoint", &redSoloWP},
    {"Blue Solo Winpoint", &blueSoloWP},
    {"Red 9 pt", &redRush},
    {"Blue 9 pt", &blueRush},
    {"Skills", &skills},
    {"Red Elim", &elimRed},
    {"Blue Elim", &elimBlue},

});

rd::Console console;

bool armpos = true;
bool spin = false;

bool ColorSortBlue = true;
bool colortoggle = true;
bool a = false;

void initialize()
{
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate();     // calibrate sensors
    arm.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
    if (a)
    {
        arm.set_zero_position(-75);
    }
    pros::Task screenTask([&]()
                          {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // y

            //controller.print(0,0, "Debug: %f", dist.get_distance());
            pros::delay(50);
        } });
    pros::Task([]
               {
    
    if(colortoggle){
        colorsens.set_led_pwm(100);
        while (true) {
            if(ColorSortBlue == true){
                if(fastintake.get_actual_velocity() >=500 && colorsens.get_hue() > 200 &&colorsens.get_hue()<260){
                    Task::delay(228);
                    fastintake.move_velocity(0);
                    Task::delay(250);
                    fastintake.move_voltage(10000);
                }
            }
            else{
                printf("%s", "Color Sorting Red");
                if(fastintake.get_target_velocity() == 600 && colorsens.get_hue() < 8){
                    Task::delay(228);
                    fastintake.move_velocity(0);
                    Task::delay(250);
                    fastintake.move_voltage(10000);
                }
            }
            pros::lcd::print(4, "Hue: %f", colorsens.get_hue());
            Task::delay(10);
        } 
    } else{
        colorsens.set_led_pwm(0);
    } });
    pros::Task([]
               {
        while(a){
            if(fastintake.get_actual_velocity()==0&&(arm.get_position()<60||arm.get_position()>80)){
                fastintake.move_voltage(-2000);
                Task::delay(300);
                fastintake.move_voltage(10000);
            }
        } });
}

void disabled() {}

void competition_initialize()
{
    // selector.focus();
}

void autonomous()
{
    // selector.run_auton();
    // skills();
    skills();
}

void opcontrol()
{

    while (true)
    {

        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        int intaketest = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) // intake
        {
            spin = !spin;
            if (spin)
            {
                intake.move_voltage(12000);
                fastintake.move_voltage(10000);
            }
            else
            {
                intake.move_voltage(0);
                fastintake.move_voltage(0);
            }
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) // l2 outtake
        {
            spin = !spin;
            if (spin)
            {
                fastintake.move_velocity(-600);
                intake.move_voltage(-10000);
            }
            else
            {
                fastintake.move_velocity(0);
                intake.move_voltage(0);
            }
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) // clamp
        {
            clamp.toggle();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) // l1 alliance stake
        {
            arm.move_absolute(600, 200);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) // r2 tip
        {
            arm.move_absolute(700, 200);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) // thumb doink
        {
            doink.toggle();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) // r1 go under ladder
        {
            arm.move_absolute(0, 200);
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) // wall stake
        {
            fastintake.move_relative(-100, 600);
            arm.move_absolute(450, 600);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) // loading
        {
            if (armpos)
            {
                if (arm.get_position() > 170)
                {
                    arm.move_absolute(75, 200);
                    armpos = false;
                }
                else
                {
                    arm.move_absolute(350, 200);
                    armpos = false;
                }
            }
            else
            {
                arm.move_absolute(75, 200);
                armpos = true;
            }
        }

        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);
        // delay to save resources
        pros::delay(10);
    }
}