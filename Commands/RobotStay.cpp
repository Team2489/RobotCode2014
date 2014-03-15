#include "RobotStay.h"
#include "../Subsystems/Chassis.h"

RobotStay::RobotStay(double timeout) {
	Requires(chassis);
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void RobotStay::Initialize() {
	chassis->stopMotion();
}

// Called repeatedly when this Command is scheduled to run
void RobotStay::Execute() {
	double val1 = chassis->getPIDValue1();
	double val2 = chassis->getPIDValue2();
//	printf("e: %f\n", val1);
//	printf("pid: %f\n", val2);
}

// Make this return true when this Command no longer needs to run execute()
bool RobotStay::IsFinished() {
	if(IsTimedOut()) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void RobotStay::End() {
	chassis->restartMotion();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotStay::Interrupted() {
	chassis->restartMotion();
}
