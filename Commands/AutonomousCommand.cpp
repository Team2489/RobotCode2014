#include "AutonomousCommand.h"
#include "DriveDistanceCommand.h"
#include "IntakeForwardBack2.h"
#include "IntakeUpDown.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "ShootBallIntoGoalGroup.h"
#include "ReleaseCatapultCommand2.h"
#include "ShiftUp.h"
#include "WaitVision.h"
#include "DriveForward.h"

AutonomousCommand::AutonomousCommand() {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        // e.g. AddParallel(new Command1());
        //      AddSequential(new Command2());
        // Command1 and Command2 will run in parallel.

        // A command group will require all of the subsystems that each member
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
	AddSequential(new WaitVision(5.0));
	// AddSequential(new ShiftUp());
//	AddSequential(new DriveDistanceCommand(-155, 1.0));
#if 1
	AddSequential(new DriveForward(0.6));
//	AddParallel(new IntakeForwardBack2(false, 0.3));
	AddSequential(new IntakeUpDown(false, 2.8));
//	printf("Autonomous point 1\n");
	//AddSequential(new ReleaseCatapultCommand2(
		//	1.0, 
			//.246
//	));
	printf("Autonomous Point 2\n");
	//AddSequential(new ResetCatapultCommand());	
//	printf("Autonomous Point 3\n");
#endif
}
