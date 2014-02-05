#ifndef TURNVARANGLE_H
#define TURNVARANGLE_H


#include "TurnAngle.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "SmartDashboard/SmartDashboard.h"

/**
 *
 *
 * @author sasha
 */
class TurnVarAngle: public CommandGroup {
private:
	TurnAngle *mycommand;
public:
	TurnVarAngle();
	void TurnVarAngle::Initialize();
};

#endif
