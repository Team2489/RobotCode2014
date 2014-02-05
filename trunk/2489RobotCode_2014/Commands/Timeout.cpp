#include "Timeout.h"

Timeout::Timeout(double timeout) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void Timeout::Initialize() {
	SetTimeout(m_timeout);
}

// Called repeatedly when this Command is scheduled to run
void Timeout::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool Timeout::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Timeout::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Timeout::Interrupted() {
}
