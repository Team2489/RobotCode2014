// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/DriveInSquare.h"
#include "Commands/DriveBackAndForth.h"
#include "Commands/AutonomousCommand.h"

#include "OI.h"
#include "Round.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	Command *teleopCommand;

	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
};
#endif

