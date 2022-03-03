#include "main.h"
#define DIGITAL_SENSOR_PORT 'A'
//#include "autoSelect/selection.h"
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
void initialize() {
 //   selector::init();
}
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
	
	pros::Motor right_mtr4(8);				// Right motor setup, (port)
	pros::Motor right_mtr5(9);
	pros::Motor right_mtr6(10);


    pros::Motor lift_mtr8(4);               // Lift motor setup, (port)
    pros::Motor lift_mtr9(5);

//	lift_mtr8 = -50;
//    lift_mtr9 = 50; // Ensure the lift starts lowering, just in case it is in a higher position


    left_mtr1 = 100;  // Move forward on all motors at speed 100
	left_mtr2 = 100;
    left_mtr3 = 100;
    right_mtr4 = -100;
    right_mtr5 = -100;
    right_mtr6 = -100;

    pros::delay(2000); // Wait 2 seconds

    left_mtr1 = 0;  // Stop all motors
	left_mtr2 = 0;
    left_mtr3 = 0;
    right_mtr4 = 0;
    right_mtr5 = 0;
    right_mtr6 = 0;
	lift_mtr8 = 0;
    lift_mtr9 = 0;


    pros::delay(20); // Small delay to let everything stop before lifting

    lift_mtr8 = 100;  // Lift
    lift_mtr8 = -100;

    pros::delay(500); // Delay to let the lift lift

   	lift_mtr8 = 0;   // stop lifting
	lift_mtr9 = 0;

    left_mtr1 = -100;  // Move back on all motors at speed -100
	left_mtr2 = -100;
    left_mtr3 = -100;
    right_mtr4 = 100;
    right_mtr5 = 100;
    right_mtr6 = 100;

    pros::delay(2000); // Same delay as earlier, hopefully this puts us where we need to be

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
	
	pros::Motor right_mtr4(8);				// Right motor setup, (port)
	pros::Motor right_mtr5(9);
	pros::Motor right_mtr6(10);


    pros::Motor lift_mtr8(4);               // Lift motor setup, (port)
    pros::Motor lift_mtr9(5);

	while (true) {
		// Fetch controller
			int left  = master.get_analog(ANALOG_LEFT_Y) * 2;
			int right = master.get_analog(ANALOG_RIGHT_Y) * 2;

/* To be rebind to another button, both bumpers and triggers will be used for the lift
            bool buttoon = master.get_digital(DIGITAL_L1);

        if  (buttoon = true) {
            int linux = 0.3 ;
        }
        else {
            int linux = 1 ;
        }
*/ int linux = 1;


		left_mtr1 = left ;								// Sets motor speed for 'left'
		left_mtr2 = left ;
		left_mtr3 = left ;
			
		right_mtr4 =- right ;							// Sets motor speed for 'right'
		right_mtr5 =- right ;
		right_mtr6 =- right  ;
		

        if (master.get_digital(DIGITAL_R1)) {
            lift_mtr8 = 100;
            lift_mtr9 = -100;
        }
        else if (master.get_digital(DIGITAL_R2)) {
            lift_mtr8 = -100;
            lift_mtr9 = 100;        }
        else {
            lift_mtr8 = 3;
            lift_mtr9 = -3;
        }

    #define DIGITAL_SENSOR_PORTA 'A'
    pros::ADIDigitalOut pistonA (DIGITAL_SENSOR_PORTA);
    pistonA.set_value(true);

    #define DIGITAL_SENSOR_PORTB 'B'
    pros::ADIDigitalOut pistonB (DIGITAL_SENSOR_PORTB);
    pistonB.set_value(true);

    #define DIGITAL_SENSOR_PORTC 'C'
    pros::ADIDigitalOut pistonC (DIGITAL_SENSOR_PORTC);
    pistonC.set_value(true);

    #define DIGITAL_SENSOR_PORTD 'D'
    pros::ADIDigitalOut pistonD (DIGITAL_SENSOR_PORTD);
    pistonD.set_value(true);


    #define DIGITAL_SENSOR_PORTE 'E'
    pros::ADIDigitalOut pistonE (DIGITAL_SENSOR_PORTE);
    pistonE.set_value(true);

    #define DIGITAL_SENSOR_PORTF 'F'
    pros::ADIDigitalOut pistonF (DIGITAL_SENSOR_PORTF);
    pistonF.set_value(true);

    #define DIGITAL_SENSOR_PORTG 'G'
    pros::ADIDigitalOut pistonG (DIGITAL_SENSOR_PORTG);
    pistonG.set_value(true);

    #define DIGITAL_SENSOR_PORTH 'H'
    pros::ADIDigitalOut pistonH (DIGITAL_SENSOR_PORTH);
    pistonH.set_value(true);
    }
}
		// Reverse the above motors by putting a - after the =



// don't compile and upload with sudo, it won't work i think or something
// remember to use pros make all to compile before using pros upload to upload
// I eat poop when I am fungrty
