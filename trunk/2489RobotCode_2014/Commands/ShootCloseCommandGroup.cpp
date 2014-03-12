#include "ShootCloseCommandGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack2.h"
#include "IntakeUpDown.h"

ShootCloseCommandGroup::ShootCloseCommandGroup() {
    // these will run in order.
	//AddParallel(new IntakeForwardBack2(false, 0.3));
	AddSequential(new IntakeUpDown(false, 0.8));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_CLOSE_COMMAND_POWER, 
			SHOOT_CLOSE_COMMAND_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}
