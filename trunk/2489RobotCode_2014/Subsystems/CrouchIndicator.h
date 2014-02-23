#ifndef CROUCHINDICATOR_H
#define CROUCHINDICATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author olga
 */
class CrouchIndicator: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CrouchIndicator();
	void InitDefaultCommand();
	void SetValue(float a_value);
};

#endif
