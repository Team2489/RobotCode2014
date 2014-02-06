#include "ShiftDown.h"

ShiftDown::ShiftDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftDown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShiftDown::Execute() {
	chassis->shiftDown();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShiftDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftDown::Interrupted() {
}
