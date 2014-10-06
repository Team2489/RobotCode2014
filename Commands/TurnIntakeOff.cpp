#include "TurnIntakeOff.h"

TurnIntakeOff::TurnIntakeOff() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(intake);
}

// Called just before this Command runs the first time
void TurnIntakeOff::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TurnIntakeOff::Execute() {
	intake->turnOff();
}

// Make this return true when this Command no longer needs to run execute()
bool TurnIntakeOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurnIntakeOff::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnIntakeOff::Interrupted() {
}