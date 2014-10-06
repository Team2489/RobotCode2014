#include "IntakeUpDown.h"
#include "../RobotMap.h"

IntakeUpDown::IntakeUpDown(bool isUp, double timeout)

{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(intake);
	intakeIsUp = isUp;
	commandIsFinished = false;
	m_timeout = timeout;

}

// Called just before this Command runs the first time
void IntakeUpDown::Initialize() {
//	printf("IntakeUpDown\n");
	if (m_timeout) {
		SetTimeout(m_timeout);
	}
}

// Called repeatedly when this Command is scheduled to run
void IntakeUpDown::Execute() {
	if(intakeIsUp) {
		intake->up();
	} else {
		intake->down();
		intake->suckIn(); // This line may cause problems!!!
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUpDown::IsFinished() {
	if (m_timeout) {
		return IsTimedOut();
	} else {
		return commandIsFinished;
	}
	
}

// Called once after isFinished returns true
void IntakeUpDown::End() {
	intake->turnOff();
	printf("IntakeUpDown::End");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUpDown::Interrupted() {
	End();
}
