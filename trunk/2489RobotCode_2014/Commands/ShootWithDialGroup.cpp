#include "ShootWithDialGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack2.h"
#include "IntakeUpDown.h"

ShootWithDialGroup::ShootWithDialGroup() {
    // these will run in order.
	//AddParallel(new IntakeForwardBack2(false, 0.3));
	AddSequential(new IntakeUpDown(false, 0.8));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_WITH_DIAL_POWER, 
			SHOOT_WITH_DIAL_DURATION
	));
	AddSequential(new ResetCatapultCommand());
	
}
