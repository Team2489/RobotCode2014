#include "Intake.h"
#include "../Commands/TurnIntakeOff.h"
#include "../Robotmap.h"

Intake::Intake() : Subsystem("Intake") {
	m_intakeSolenoid1 = new DoubleSolenoid(INTAKE_SOLENOID1_LEFT_PORT,INTAKE_SOLENOID1_RIGHT_PORT);
	m_intakeJaguar1 = new Jaguar(INTAKE_JAGUAR_PWM);
	m_intakeSolenoid1->Set(DoubleSolenoid::kOff);
}
    
void Intake::InitDefaultCommand() {
	SetDefaultCommand(new TurnIntakeOff());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::up() {
	m_intakeSolenoid1->Set(DoubleSolenoid::kForward);
}

void Intake::down() {
	m_intakeSolenoid1->Set(DoubleSolenoid::kReverse);
}

void Intake::turnOff() {
	m_intakeJaguar1->Set(0.0);
}
void Intake::spitOut() {
	m_intakeJaguar1->Set(1.0);
}

void Intake::suckIn() {
	m_intakeJaguar1->Set(-1.0);
}

bool Intake::getSolenoid() {
	return (m_intakeSolenoid1->Get() == DoubleSolenoid::kForward);
}
