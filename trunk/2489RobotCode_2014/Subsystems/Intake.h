#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Vignesh
 */
class Intake: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DoubleSolenoid* m_intakeSolenoid1;
	Jaguar* m_intakeJaguar1;
	Intake();
	void InitDefaultCommand();
	void down();
	void up();
	void suckIn();
	void spitOut();
	void turnOff();
	bool getSolenoid();
};

#endif
