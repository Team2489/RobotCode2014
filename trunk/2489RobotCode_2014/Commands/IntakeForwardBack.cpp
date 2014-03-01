#include "IntakeForwardBack.h"

IntakeForwardBack::IntakeForwardBack(bool isSpit, double timeout) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(intake);
	spit = isSpit;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void IntakeForwardBack::Initialize() {
	if (m_timeout) {
		SetTimeout(m_timeout);
	}
}

// Called repeatedly when this Command is scheduled to run
void IntakeForwardBack::Execute() {
	if(spit) {
		intake->spitOut();
	} else {
		intake->suckIn();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeForwardBack::IsFinished() {
	if (m_timeout) {
		return IsTimedOut();
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void IntakeForwardBack::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeForwardBack::Interrupted() {
}
