#include "ResetCatapultCommand.h"
#include "../RobotMap.h"

ResetCatapultCommand::ResetCatapultCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(catapult);
}

// Called just before this Command runs the first time
void ResetCatapultCommand::Initialize() {
	SetTimeout(3.0);
}

// Called repeatedly when this Command is scheduled to run
void ResetCatapultCommand::Execute() {
	catapult->RunCatapultMotors(-1*CATAPULT_RESET_POWER);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetCatapultCommand::IsFinished() {
	return (catapult->IsCatapultReset())|| IsTimedOut();
}

// Called once after isFinished returns true
void ResetCatapultCommand::End() {
	catapult->RunCatapultMotors(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetCatapultCommand::Interrupted() {
	End();
}
