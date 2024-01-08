#include "main.h"
#include "functions.hpp"
#include "timing.hpp"
using namespace pros;
//Testing 
Controller master(E_CONTROLLER_MASTER);
    Motor leftfrontmtr(16);
    Motor rightfrontmtr(5);
    Motor leftbackmtr(10);
    Motor rightbackmtr(3);
    Motor intakemtr(19);
    Motor flywheelmtr(21);

	Motor leftArm(20);
	Motor rightArm(15);
    Imu inertial_sensor(1);
    Imu gps_sensor(4);
	ADIDigitalOut armFlapL(1);
    ADIDigitalOut armFlapR(6);

/**
 * A callback function for LLEMU's center button.
 *hi joshuwar i am typing on phon hi
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "4471A!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	inertial_sensor.reset();
	//pros::gps::initialize();
	delay(2000);
	//pusharm.set_value(1);

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
	inertial_sensor.tare_rotation();
	inertial_sensor.tare_pitch();
	leftbackmtr.tare_position();
	leftfrontmtr.tare_position();
	rightbackmtr.tare_position();
	rightfrontmtr.tare_position();
	leftArm.tare_position();
	rightArm.tare_position();
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
void autonomous(){

	//****SKILLS AUTO****

	/*
	moveBack(850, 0.1, 2000);
	delay(300);
	turnLeft(110, 2000);
	delay(200);
	moveBack(900, 0.1, 2075);
	spinToWin(28000);
	delay(500);
	moveForward(150, 1.2, 2000);
	delay(500);
	turnLeft(105, 2000);
	delay(500);
	moveBack(680, 0.2, 2000);
	delay(300);
	turnLeft(58, 2000);
	delay(300);
	forceMove(-600, 1000);
	//moveBack(1550, 0.4, 2000);
	//delay(300);
	curve(300, 50, 4, 2500);
	delay(300);
	intakeOn(-127);
	moveForward(400, 0.2, 2000);
	//curve(80, 55, 1, 600);
	//delay(100);
	//curve(300, 65, 4, 1000);
	//delay(300);
	//curve(80, 55, 1, 600);
	//delay(100);
	//curve(300, 65, 4, 1000);
	//delay(300);
	//curve(80, 55, 1, 600);
	//delay(100);
	//curve(300, 65, 4, 1000);
	moveBack(800, 1, 2000);
	moveForward(400, 0.5, 2000);
	delay(300);
	moveBack(800, 1, 2000);
	delay(300);
	moveForward(400, 0.5, 2000);
	delay(300);
	moveBack(800, 1, 2000);
	delay(300);
	moveForward(150, 0.8, 2000);
	delay(300);
	turnRight(120, 2000);
	delay(300);
	moveBack(1000, 0.6, 2000);
	delay(300);
	moveForward(1500, 0.8, 2000);
	delay(100);
	turnRight(90, 2000);
	delay(100);
	doFlaps(1);
	curve(300, 30, 1, 1500);
	delay(100);
	doFlaps(0);
	//moveBack(600, 0.6, 2000);
	moveBack(800, 0.5, 2000);
	doFlaps(1);
	delay(100);
	turnLeft(20, 1000);
	delay(100);
	//moveForward(1000, 1, 2000);
	moveForward(1200, 1, 2000);
	*/




	//****MATCH LOADING****

	/*
	intakeOn(127);
	moveBack(500, 1, 1000);
	delay(300);
	moveForward(100, 0.8, 1000);
	delay(300);
	turnLeft(45, 2000);
	delay(300);
	moveForward(650, 0.3, 2000);
	delay(300);
	turnRight(48, 2000);
	delay(300);
	moveForward(1000, 1, 2000);
	delay(300);
	moveBack(200, 0.5, 2000);
	delay(300);
	turnRight(135, 2000);
	delay(300);
	moveForward(860, 0.2, 3000);
	delay(300);
	turnLeft(40, 2000);
	delay(300);
	moveForward(755, 0.2, 4000);
	*/


	//****MATCH NOT LOADING****


	intakeOn(127);
	moveBack(500, 1, 1000);
	delay(300);
	moveForward(100, 0.8, 1000);
	delay(300);
	turnRight(45, 2000);
	delay(300);
	moveForward(650, 0.3, 2000);
	delay(300);
	turnLeft(48, 2000);
	delay(300);
	moveForward(1000, 1, 2000);
	delay(300);
	moveBack(200, 0.5, 2000);
	delay(300);
	turnLeft(135, 2000);
	delay(300);
	moveForward(860, 0.2, 3000);
	delay(300);
	turnRight(40, 2000);
	delay(300);
	moveForward(755, 0.2, 4000);


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
 * If the rohi bot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {


	int intakeState = 0;
 	int revintakeState = 0;
	int flywheelState = 0;
	int armFlapState = 0;
	leftArm.tare_position();
	rightArm.tare_position();
	armFlapL.set_value(0);
	armFlapR.set_value(0);

	/*
	while (true) {
		pros::lcd::set_text(2, int(leftArm.get_position()));
		pros::lcd::set_text(3, int(rightArm.get_position()));
		delay(1000);
	}*/

 	while (true) {

 		int leftY = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_X);
 		leftfrontmtr = -leftY - turn;
 		leftbackmtr = -leftY - turn;
 		rightfrontmtr = leftY - turn;
 		rightbackmtr = leftY - turn;

 		if (master.get_digital_new_press(DIGITAL_R1) == 1){
 			if (intakeState == 0){
 				intakeState = 1;
 				//intakemtr.move_voltage(10000);
				intakemtr = -127;
 			}
 			else if (intakeState == 1){
 				intakeState = 0;
 				//intakemtr.move_voltage(0);
				intakemtr = 0;
 			}
 		}

		if (master.get_digital_new_press(DIGITAL_A) == 1) {
			if (armFlapState == 0) {
				armFlapL.set_value(1);
				armFlapR.set_value(1);
				armFlapState = 1;
			}
			else {
				armFlapL.set_value(0);
				armFlapR.set_value(0);
				armFlapState = 0;
			}
		}

		if (master.get_digital_new_press(DIGITAL_B) == 1) {
			if (flywheelState == 0) {
				flywheelmtr = 500;
				flywheelState = 1;
			}
			else {
				flywheelmtr = 0;
				flywheelState = 0;
			}
		}


 		if (master.get_digital_new_press(DIGITAL_X) == 1) {
 			if (revintakeState == 0){
 				revintakeState = 1;
				intakemtr = 127;
 			}
 			else if (revintakeState == 1){
 				revintakeState = 0;
 				intakemtr = 0;
 			}
 		}

		if (master.get_digital_new_press(DIGITAL_Y) == 1) {
			if (flywheelState == 0) {
				flywheelmtr = -500;
				flywheelState = 1;
			}
			else {
				flywheelmtr = 0;
				flywheelState = 0;
			}
		}


		if (master.get_digital_new_press(DIGITAL_DOWN) == 1) {
			if (flywheelState == 0) {
				flywheelmtr = 95;
				flywheelState = 1;
			}
			else {
				flywheelmtr = 0;
				flywheelState = 0;
			}
		}

		if (master.get_digital_new_press(DIGITAL_L1) == 1) {
			moveArm(1);
		}

		if (master.get_digital_new_press(DIGITAL_L2) == 1) {
			moveArm(0);
		}
 	}
}
