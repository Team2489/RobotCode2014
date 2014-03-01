#include "IntakeUpDown.h"
#include "../RobotMap.h"

IntakeUpDown::IntakeUpDown(bool isUp)

{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(intake);
	intakeIsUp = isUp;
	commandIsFinished = false;

}

// Called just before this Command runs the first time
void IntakeUpDown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void IntakeUpDown::Execute() {
	if(intakeIsUp) {
		intake->up();
	} else {
		intake->down();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUpDown::IsFinished() {
	return commandIsFinished;
}

// Called once after isFinished returns true
void IntakeUpDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUpDown::Interrupted() {
}
