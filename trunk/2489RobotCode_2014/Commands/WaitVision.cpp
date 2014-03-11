#include "WaitVision.h"

WaitVision::WaitVision(double timeout) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(targetingControl);
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void WaitVision::Initialize() {
	SetTimeout(m_timeout);
}

// Called repeatedly when this Command is scheduled to run
void WaitVision::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WaitVision::IsFinished() {
	double d;
	int dstate;
	int ret = CommandBase::targetingControl->vc->GetState(&d, &dstate);
	if (ret == 0){
		if(dstate){
			return true;
		}
	}
	return IsTimedOut();
}

// Called once after isFinished returns true
void WaitVision::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitVision::Interrupted() {
}
