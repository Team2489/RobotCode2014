#include "ShiftGear.h"

ShiftGear::ShiftGear() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftGear::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShiftGear::Execute() {
	chassis->switchGear();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftGear::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShiftGear::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftGear::Interrupted() {
}
