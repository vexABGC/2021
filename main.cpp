#include "main.h"

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





/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_left_button() {
	
	#define DIGITAL_SENSOR_PORT 'A'
	
	
	//pros::ADIDigitalOut piston (uint8_t A);
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		//piston.set_value(true);
		pros::ADIDigitalOut piston (DIGITAL_SENSOR_PORT);
  		piston.set_value(true);
  		pros::delay(1000);
  		piston.set_value(false);
	} else {
		pros::lcd::clear_line(2);
	}
}

void on_right_button() {
//	pros::ADIDigitalOut piston (uint8_t A);
//	static bool pressed = false;
//	pressed = !pressed;
//	if (pressed) {
//		piston.set_value(false);
//	} else {
//		pros::lcd::clear_line(2);
//	}
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "hello gamer pro gamer");
	pros::lcd::set_text(2, "linux is cool");

	pros::lcd::register_btn1_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_right_button);



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
void competition_initialize() {
	pros::lcd::set_text(3, "Competition");
}

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

// this is for eric, do it

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
	// Motor and controller setup for AWD and lift
	pros::Controller master(pros::E_CONTROLLER_MASTER); 	// Controller setup
	
	pros::Motor left_mtr1(1);				// Left motor 1 setup, (port)
	pros::Motor left_mtr2(2);				// Left motor 2
	
	pros::Motor right_mtr5(5);				// Right motor 3 setup, (port)
	pros::Motor right_mtr4(4);				// Right motor 4 setup, (port)

	pros::Motor ghgh(7); 
	
	
	
	
	
	while (true) {
//		pros::c::battery_get_capacity batcapacity;
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2, // Left button
		
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,		// Center button
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);		// Right button
		                 
		int left =- master.get_analog(ANALOG_LEFT_Y);					// Controller tank controls
		int right = master.get_analog(ANALOG_RIGHT_Y);					// Goes to variables 'left' and 'right'
		
		int lift1 = master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2);	// Lift

		int miving = master.get_digital(DIGITAL_R1) - master.get_digital(DIGITAL_R2);

		
		// Speed multiplier 
/*		if (master.get_digital(DIGITAL_L2 = 0) {
			if (master.get_digital(DIGITAL_L1 = 0) {
				int linux = 0.7;
			}
			
			else {
				if (master.get_digital(DIGITAL_L2 = 0) {
					int linux = 0.3
				}
				else {
					int linux = 1
				}
			}	
		} 
*/
		left_mtr1 = left;// * linux;								// Sets motor speed for 'left'
		left_mtr2 = left;// * linux;								//
			
		right_mtr5 = right;// * linux;								// Sets motor speed for 'right'
		right_mtr4 = right;// * linux;
		
		ghgh = lift1;
		
		// Reverse the above motors by putting a - after the =
		
		
		
		pros::delay(20);								// Delay 
		
		
	}
}


// don't compile and upload with sudo, it won't work i think or something
// remember to use pros make all to compile before using pros upload to upload
