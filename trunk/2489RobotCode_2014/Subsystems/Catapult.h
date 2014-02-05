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
	
	SpeedController* m_catapultMotor1;
	SpeedController* m_catapultMotor2;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Catapult();
	void InitDefaultCommand();
	void RunCatapultMotors(float, float);
};

#endif
