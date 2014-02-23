#include "CrouchIndicatorCommand.h"

CrouchIndicatorCommand::CrouchIndicatorCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(crouchIndicator);
}

// Called just before this Command runs the first time
void CrouchIndicatorCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CrouchIndicatorCommand::Execute() {
	crouchIndicator->SetValue(oi->getCrouch());
}

// Make this return true when this Command no longer needs to run execute()
bool CrouchIndicatorCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CrouchIndicatorCommand::End() {
	crouchIndicator->SetValue(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrouchIndicatorCommand::Interrupted() {
	crouchIndicator->SetValue(0);
}
