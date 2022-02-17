#include "main.h"
#define DIGITAL_SENSOR_PORT 'A'

/**
Notes about how to use and upload this code
Made using PROS, probably will not work without it installed https://pros.cs.purdue.edu/
You will need to make a project, replace main.cpp in src/ with this file, then you can compile it 
Wiring:
1, 2 	- Left motors
3, 4 	- Right motors
5	- Lift
All operator control code (pretty much everything) is in the operator_control function at the bottom
If you need to reverse something, put a minus after the = where the code says to set the speed
If you need anything majorly changed, please open an issue on Github: https://github.com/NULL0404/vexrobotics/
It's a private repository, you will need to log in and or have me add you to the repo, dm me on discord
**/
void initialize() {}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
/*
 * Note: This autonomous code is UNTESTED and was created prior to robot construction.
 * Make sure the code is up to  date by using 'git pull'
 *
 * This should go forward, grab the ring holder, and retreat. Variables to be changed
*/

    pros::Controller master(pros::E_CONTROLLER_MASTER); 	// Controller setup

	pros::Motor left_mtr1(1);				// Left motor setup, (port)
	pros::Motor left_mtr2(2);
	pros::Motor left_mtr3(3);

	pros::Motor right_mtr4(4);				// Right motor setup, (port)
	pros::Motor right_mtr5(5);
	pros::Motor right_mtr6(6);

    pros::Motor lift_mtr8(8);
    pros::Motor lift_mtr9(9);


	bool aliftstate = false;				// Sets the lift state by default

	lift_mtr8 = -50;
    lift_mtr9 = 50; // Ensure the lift starts lowering, just in case it is in a higher position


    left_mtr1 = 70;  // Move forward on all motors at speed 70
	left_mtr2 = 70;
    left_mtr3 = 70;
    right_mtr4 = 70;
    right_mtr5 = 70;
    right_mtr6 = 70;

    pros::delay(200); // Wait 2 seconds

    left_mtr1 = 0;  // Stop all motors
	left_mtr2 = 0;
    left_mtr3 = 0;
    right_mtr4 = 0;
    right_mtr5 = 0;
    right_mtr6 = 0;
	lift_mtr8 = 0;
    lift_mtr9 = 0;


    pros::delay(20); // Small delay to let everything stop before lifting

    lift_mtr8 = 70;  // Lift
    lift_mtr8 = -70;

    pros::delay(50); // Delay to let the lift lift

   	lift_mtr8 = 0;   // stop lifting
	lift_mtr9 = 0;

    left_mtr1 = -70;  // Move back on all motors at speed -70
	left_mtr2 = -70;
    left_mtr3 = -70;
    right_mtr4 = -70;
    right_mtr5 = -70;
    right_mtr6 = -70;

    pros::delay(200); // Same delay as earlier, hopefully this puts us where we need to be

    left_mtr1 = 0;  // Stop all motors
	left_mtr2 = 0;
    left_mtr3 = 0;
    right_mtr4 = 0;
    right_mtr5 = 0;
    right_mtr6 = 0;
	lift_mtr8 = 0;
    lift_mtr9 = 0;
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER); 	// Controller setup
	
	pros::Motor left_mtr1(1);				// Left motor setup, (port)
	pros::Motor left_mtr2(2);				
	pros::Motor left_mtr3(3);
	
	pros::Motor right_mtr4(4);				// Right motor setup, (port)
	pros::Motor right_mtr5(5);				
	pros::Motor right_mtr6(6);	


    pros::Motor lift_mtr8(8);               // Lift motor setup, (port)
    pros::Motor lift_mtr9(9);

	
    int linux = 1;

	while (true) {
		// Fetch controller
			int left =- master.get_analog(ANALOG_LEFT_Y);					
			int right = master.get_analog(ANALOG_RIGHT_Y);	

			bool aliftup = master.get_digital(DIGITAL_R2);
			bool aliftdown = master.get_digital(DIGITAL_R1);

            bool bliftup = master.get_digital(DIGITAL_R2);
			bool bliftdown = master.get_digital(DIGITAL_R1);

/* To be rebind to another button, both bumpers and triggers will be used for the lift
            bool buttoon = master.get_digital(DIGITAL_L1);

        if  (buttoon = true) {
            int linux = 0.3 ;
        }
        else {
            int linux = 1 ;
        }
*/ int linux = 1;

		left_mtr1 = left * linux;								// Sets motor speed for 'left'
		left_mtr2 = left * linux;
		left_mtr3 = left * linux;
			
		right_mtr4 = right * linux;								// Sets motor speed for 'right'
		right_mtr5 = right * linux;
		right_mtr6 = right * linux;
		
		// Reverse the above motors by putting a - after the =

        if (bool aliftup = true) {
            lift_mtr8 = 70;
            lift_mtr9 = -70;
			}
		}
		if (bool aliftdown = true) {
            lift_mtr8 = -70;
            lift_mtr9 = 70;
			}
		}
		


// don't compile and upload with sudo, it won't work i think or something
// remember to use pros make all to compile before using pros upload to upload
// I eat poop when I am fungrty
