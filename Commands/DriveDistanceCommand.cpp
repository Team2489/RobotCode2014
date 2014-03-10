#include "DriveDistanceCommand.h"
#include "../RobotMap.h"

DriveDistanceCommand::DriveDistanceCommand(float distance, float power):
	m_InitialValueRight(0),
	m_InitialValueLeft(0),
	m_distance(distance),
	m_power(power) {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
	m_encoderTicksToTravel = (int)(distance * ENCODER_PULSE_PER_INCH);
}

// Called just before this Command runs the first time
void DriveDistanceCommand::Initialize() {
	chassis->m_encoderRight->Start();
	chassis->m_encoderLeft->Start();
	m_InitialValueRight = chassis->m_encoderRight->Get();
	m_InitialValueLeft = chassis->m_encoderLeft->Get();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceCommand::Execute() {
	if(m_encoderTicksToTravel > 0) {
		chassis->goStraight(m_power);
	} else {
		chassis->goBack(m_power);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCommand::IsFinished() {
	int encoderTickRight = chassis->m_encoderRight->Get() - m_InitialValueRight;
	int encoderTickLeft = chassis->m_encoderLeft->Get() - m_InitialValueLeft;
	
	bool leftDone;
	bool rightDone;
	if (m_distance > 0){
		leftDone = (encoderTickLeft >= m_encoderTicksToTravel);
		rightDone = (encoderTickRight >= m_encoderTicksToTravel);	
	}
	else {
		leftDone = (encoderTickLeft <= m_encoderTicksToTravel);
		rightDone = (encoderTickRight <= m_encoderTicksToTravel);
	}
	return (leftDone || rightDone);
}

// Called once after isFinished returns true
void DriveDistanceCommand::End() {
	chassis->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCommand::Interrupted() {
	chassis->stop();
}
