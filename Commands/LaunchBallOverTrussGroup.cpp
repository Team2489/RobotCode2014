#include "LaunchBallOverTrussGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeUpDown.h"
#include "IntakeForwardBack.h"

LaunchBallOverTrussGroup::LaunchBallOverTrussGroup() {
	// these will run in order.
	// nate was here
	AddSequential(new IntakeUpDown(false, 1.0)); //2.5
	//AddSequential(new IntakeForwardBack(false, 1.4));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_OVER_THE_TRUSS_POWER, 
			SHOOT_OVER_THE_TRUSS_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}	

       
