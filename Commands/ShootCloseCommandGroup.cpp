#include "ShootCloseCommandGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack.h"
#include "IntakeUpDown.h"

ShootCloseCommandGroup::ShootCloseCommandGroup() {
    // these will run in order.
	AddSequential(new IntakeUpDown(false, 1.0)); //2.5
	//AddSequential(new IntakeForwardBack(false, 1.4));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_CLOSE_COMMAND_POWER, 
			SHOOT_CLOSE_COMMAND_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}
