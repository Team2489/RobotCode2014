#include "ReverseChassisDirectionControlCommand.h"
//This command reverses the driving direction of robot for joystick driving
//LED light lights up accordingly

ReverseChassisDirectionControlCommand::ReverseChassisDirectionControlCommand(bool a_value) {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
	m_reverseDirection = a_value;
	
}

// Called just before this Command runs the first time
void ReverseChassisDirectionControlCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ReverseChassisDirectionControlCommand::Execute() {
	chassis->setReverseDirectionControl(m_reverseDirection);
	oi->SetLEDState(m_reverseDirection);
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseChassisDirectionControlCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ReverseChassisDirectionControlCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseChassisDirectionControlCommand::Interrupted() {
}
