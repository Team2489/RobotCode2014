// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

//Do not commit it defined, for testbot only
//#define TESTERBOT 1

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
#define MODULE1NUM 1
// Jaguars Talons and Motors
#define CHASSISLEFTMOTORPWM 2
#define CHASSISRIGHTMOTORPWM 1

//Catapult
#define CATAPULT_MOTOR_1_PWM 5
#define CATAPULT_MOTOR_2_PWM 6
#define CATAPULT_MOTOR_3_PWM 7
#define CATAPULT_SENSOR_IO   14
#define CATAPULT_SENSOR2_IO  15

#define SHOOT_FOR_THE_GOAL_POWER 		1.00
// this is a value for shooting from about 0 to 1 foot from the fender
#define SHOOT_FOR_THE_GOAL_DURATION 	.248

#define SHOOT_CLOSE_COMMAND_POWER 		1.00
#define	SHOOT_CLOSE_COMMAND_DURATION	.188

#define SHOOT_WITH_DIAL_POWER			1.00
#define	SHOOT_WITH_DIAL_DURATION		0

#define CATAPULT_RESET_POWER			0.15
#define SHOOT_OVER_THE_TRUSS_POWER		1.00 //0.90
// rely on the value from the dial on the driver station
#define SHOOT_OVER_THE_TRUSS_DURATION 	0 

//Solenoids
#define PUMPSPIKESOLENOID 1
#define UPSOLENOID 1
#define DOWNSOLENOID 2

//Encoders
#define CHASSIS_ENCODER_RIGHT_PORT_1 	2
#define CHASSIS_ENCODER_RIGHT_PORT_2 	3
#define CHASSIS_ENCODER_LEFT_PORT_1  	11
#define CHASSIS_ENCODER_LEFT_PORT_2  	12

// THis value was measured by driving the robot for 100".  
#define ENCODER_PULSE_PER_INCH			14.37

//Analog 
#define CHASSISGYROANALOG 1

//Digital
#define PUMPSWITCHDIGITAL 1


//Abstract
#define TESTINGSPEED 0.3

//Intake Solenoid
#define INTAKE_SOLENOID1_RIGHT_PORT 4
#define INTAKE_SOLENOID1_LEFT_PORT 5

//Intake Jaguar
#define INTAKE_JAGUAR_PWM 8

#ifdef TESTERBOT
#define TURNANGLETOLERENCE 0.001
#define TURNANGLEDELTA 0.005
#define TURNANGLEZONE  0.14
#define COMPENSATION 1.0
#else
#define TURNANGLETOLERENCE 0.001
#define TURNANGLEDELTA 0.01
#define TURNANGLEZONE  0.08
#define COMPENSATION 1.05
#endif
#endif
