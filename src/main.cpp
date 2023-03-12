#include "main.h"




 sylib::SpeedControllerInfo motor_speed_controller (
        [](double rpm){return 5;}, // kV function
        1, // kP
        1, // kI
        1, // kD
        1, // kH
        false, // anti-windup enabled
        0, // anti-windup range
        false, // p controller bounds threshold enabled
        0, // p controller bounds cutoff enabled
        1, // kP2 for when over threshold
        0 // range to target to apply max voltage
    );
 
    // Create a motor object on port 17, with a green cart, set as reversed, and with
    // motor_speed_controller as a custom velocity controller
    auto motor = sylib::Motor(17,200, true, motor_speed_controller);


void initialize() {
	sylib::initialize();
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
void autonomous() {}

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
	while(true){
		motor.set_velocity_custom_controller(3600); 
	}
}