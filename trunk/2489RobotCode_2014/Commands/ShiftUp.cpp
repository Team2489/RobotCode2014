#include "ShiftUp.h"

ShiftUp::ShiftUp() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftUp::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShiftUp::Execute() {
	chassis->shiftUp();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftUp::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShiftUp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftUp::Interrupted() {
}
