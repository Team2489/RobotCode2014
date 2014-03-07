#include "Catapult.h"
#include "../Robotmap.h"
#include "../Commands/StopCatapultMotors.h"

Catapult::Catapult() : Subsystem("catapult"),
	m_catapultMotor1(CATAPULT_MOTOR_1_PWM),
	m_catapultMotor2(CATAPULT_MOTOR_2_PWM),
	m_catapultMotor3(CATAPULT_MOTOR_3_PWM),
	m_sensor(CATAPULT_SENSOR_IO)
{

}
    
void Catapult::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new StopCatapultMotors());
}

void Catapult::RunCatapultMotors(float speed){
	m_catapultMotor1.Set(-speed);
	m_catapultMotor2.Set(-speed);
	m_catapultMotor3.Set(-speed);
}

bool Catapult::IsCatapultReset() {
	return !m_sensor.Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
