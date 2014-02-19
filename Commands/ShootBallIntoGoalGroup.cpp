#include "ShootBallIntoGoalGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"

ShootBallIntoGoalGroup::ShootBallIntoGoalGroup() {
    // these will run in order.
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_FOR_THE_GOAL_POWER, 
			SHOOT_FOR_THE_GOAL_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}
