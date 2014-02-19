#ifndef CATAPULT_H
#define CATAPULT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Sasha
 */
class Catapult: public Subsystem {

private:
	Jaguar m_catapultMotor1;
	Jaguar m_catapultMotor2;
	Jaguar m_catapultMotor3;
	
	DigitalInput m_sensor;	
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Catapult();
	void InitDefaultCommand();
	void RunCatapultMotors(float speed);
	bool IsCatapultReset();
};

#endif
