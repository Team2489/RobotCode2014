#include "RunCatapultTest.h"

RunCatapultTest::RunCatapultTest(float speed, float timeout) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(catapult);

	m_speed = speed;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void RunCatapultTest::Initialize() {
	if(m_timeout){
		SetTimeout(m_timeout);
	}
	
	
}

// Called repeatedly when this Command is scheduled to run
void RunCatapultTest::Execute() {
	if(m_speed){
		catapult->RunCatapultMotors(m_speed, m_speed);
	}
	else{
		catapult->RunCatapultMotors(oi->getCatapultSpeed(), oi->getCatapultSpeed());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunCatapultTest::IsFinished() {
	if(m_timeout){
		return IsTimedOut();
	}
	return false;
}

// Called once after isFinished returns true
void RunCatapultTest::End() {
	catapult->RunCatapultMotors(0, 0);
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunCatapultTest::Interrupted() {
}
