#include "StopCatapultMotors.h"

StopCatapultMotors::StopCatapultMotors() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(catapult);
}

// Called just before this Command runs the first time
void StopCatapultMotors::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void StopCatapultMotors::Execute() {
	catapult->RunCatapultMotors(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool StopCatapultMotors::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopCatapultMotors::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCatapultMotors::Interrupted() {
}
