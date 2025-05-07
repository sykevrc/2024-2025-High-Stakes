#include "main.h"
#include "robodash/api.h"
rd::Selector selector({
    {"Skills", &skills},
    {"Red WP", &RWP},
    {"BlueWP", &BWP},
    {"RdLeft", &RLE},
    {"RRight", &RRE},
    {"BlLeft", &BLE},
    {"BRight", &BRE},

});

rd::Console console;

bool armpos = true;
bool spin = false;

bool ColorSortBlue = true;
bool colortoggle = true;
void next()
{
    selector.next_auton();
}
void initialize()
{
    arm.tare_position();
    pros::Task([]
               {
        while(true){
        std::optional<rd::Selector::routine_t> current_routine = selector.get_auton();

        if(current_routine == std::nullopt){
            colorsens.set_led_pwm(100);
            if (fastintake.get_actual_velocity() >= 500 && colorsens.get_hue() > 200 && colorsens.get_hue() < 260)
            {
                while (line.get_value() > 2700)
                {
                    fastintake.move_voltage(10000);
                }
                delay(75);
                fastintake.move_velocity(0);
                delay(250);
                fastintake.move_voltage(10000);
            }
            delay(10);
        }
        pros::delay(50);
    } });
    // pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    arm.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
    arm.set_zero_position(-75);

    // pros::Task screenTask([&]()
    //                       {
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // y

    //         //controller.print(0,0, "Debug: %f", dist.get_distance());
    //         pros::delay(50);
    //     } });.
    pros::screen::touch_callback(next, TOUCH_PRESSED);

    selector.on_select([](std::optional<rd::Selector::routine_t> routine)
                       {
		if (routine == std::nullopt) {
			//std::cout << "No routine selected" << std::endl;
		} else {
			//std::cout << "Selected Routine: " << routine.value().name << std::endl;
            controller.print(0,0, "Auto: %s", routine.value().name);
            //controller.rumble(".-.");
		} });
}

void disabled()
{
}

void competition_initialize()
{
    selector.focus();
}

void autonomous()
{
    selector.run_auton();
    // skills();
    // BLE();
}

void opcontrol()
{

    while (true)
    {

        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // int intaketest = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
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

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) // R1 outtake
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
            armpos = true;
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) // r2 tip
        {
            arm.move_absolute(700, 200);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) // thumb doink
        {
            doink.toggle();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) // L2 go under ladder
        {
            arm.move_absolute(0, 200);
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) // wall stake
        {
            fastintake.move_relative(-100, 600);
            arm.move_absolute(450, 600);
            delay(250);
            fastintake.move_voltage(10000);
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) // move up
        {
            arm.move_relative(10, 600);
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) // move down
        {
            arm.move_relative(-10, 600);
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) // tare arm
        {
            arm.tare_position();
            arm.set_zero_position(-75);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) // loading
        {
            if (armpos)
            {
                if (arm.get_position() > 170 && arm.get_position() < 550)
                {
                    arm.move_absolute(75, 200);
                    armpos = false;
                }
                else
                {
                    arm.move_absolute(300, 200);
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