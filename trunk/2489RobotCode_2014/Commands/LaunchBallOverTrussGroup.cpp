#include "LaunchBallOverTrussGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"

LaunchBallOverTrussGroup::LaunchBallOverTrussGroup() {
	// these will run in order.
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_OVER_THE_TRUSS_POWER, 
			SHOOT_OVER_THE_TRUSS_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}	

       
