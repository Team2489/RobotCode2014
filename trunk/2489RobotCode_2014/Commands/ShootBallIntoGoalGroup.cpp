#include "ShootBallIntoGoalGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack.h"
#include "IntakeUpDown.h"

ShootBallIntoGoalGroup::ShootBallIntoGoalGroup() {
    // these will run in order.
	AddSequential(new IntakeUpDown(false, 1.0)); //2.5
	//AddSequential(new IntakeForwardBack(false, 1.4));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_FOR_THE_GOAL_POWER, 
			SHOOT_FOR_THE_GOAL_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}
