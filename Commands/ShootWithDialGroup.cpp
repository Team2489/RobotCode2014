#include "ShootWithDialGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack.h"
#include "IntakeUpDown.h"

ShootWithDialGroup::ShootWithDialGroup() {
    // these will run in order.
	AddSequential(new IntakeUpDown(false, 1.0)); //2.8
	//AddSequential(new IntakeForwardBack(false, 1.4));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_WITH_DIAL_POWER, 
			SHOOT_WITH_DIAL_DURATION
	));
	AddSequential(new ResetCatapultCommand());
	
}
