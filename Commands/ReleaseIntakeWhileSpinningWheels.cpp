#include "ReleaseIntakeWhileSpinningWheels.h"
#include "../Subsystems/Intake.h"

ReleaseIntakeWhileSpinningWheels::ReleaseIntakeWhileSpinningWheels(double timeout) {
	// Use requires() here to declare subsystem dependencies
	Requires(intake);
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void ReleaseIntakeWhileSpinningWheels::Initialize() {
	if (m_timeout) {
		SetTimeout(m_timeout);
	}
}

// Called repeatedly when this Command is scheduled to run
void ReleaseIntakeWhileSpinningWheels::Execute() {
	intake->suckIn();
	intake->down();
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseIntakeWhileSpinningWheels::IsFinished() {
	if (m_timeout) {
		return IsTimedOut();
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void ReleaseIntakeWhileSpinningWheels::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseIntakeWhileSpinningWheels::Interrupted() {
}
