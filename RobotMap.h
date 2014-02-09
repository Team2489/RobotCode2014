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
#define CATAPULTMOTOR2PWM 4
#define CATAPULTMOTOR1PWM 3

//Solenoids
#define PUMPSPIKESOLENOID 1
#define UPSOLENOID 3
#define DOWNSOLENOID 2

//Analog 
#define CHASSISGYROANALOG 1

//Digital
#define PUMPSWITCHDIGITAL 1


//Abstract
#define TESTINGSPEED 0.3


//#define TESTERBOT 1
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