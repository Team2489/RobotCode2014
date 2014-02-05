#include "Catapult.h"
#include "../Robotmap.h"
#include "../Commands/StopCatapultMotors.h"

Catapult::Catapult() : Subsystem("catapult") {
	m_catapultMotor1 = new Talon(MODULE1NUM, CATAPULTMOTOR1PWM);
	m_catapultMotor2 =  new Talon(MODULE1NUM, CATAPULTMOTOR2PWM);
}
    
void Catapult::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new StopCatapultMotors());
}

void Catapult::RunCatapultMotors(float speed1, float speed2){
	m_catapultMotor1->Set(speed1);
	m_catapultMotor2->Set(speed2);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
