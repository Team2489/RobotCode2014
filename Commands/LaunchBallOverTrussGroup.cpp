#include "LaunchBallOverTrussGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeUpDown.h"

LaunchBallOverTrussGroup::LaunchBallOverTrussGroup() {
	// these will run in order.
		//AddParallel(new IntakeForwardBack2(false, 0.3));
		AddSequential(new IntakeUpDown(false, 0.8));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_OVER_THE_TRUSS_POWER, 
			SHOOT_OVER_THE_TRUSS_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}	

       
