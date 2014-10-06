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
#include "IntakeForwardBack.h"
//#include "../OI.h"

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

//	AddSequential(new WaitVision(5.0));
	AddSequential(new DriveDistanceCommand(212, 0.75));
	AddSequential(new IntakeForwardBack(true,0.2));
	AddSequential(new DriveDistanceCommand(3, 0.6));
	
	if (CommandBase::oi->getAutonomousCatapultState()== true) {
		printf("AutonomousCommand::AutonomousCommand() - Catapult enabled on driver station\n");

		printf("AutonomousCommand::AutonomousCommand() - schedule IntakeUpDown\n");
		AddSequential(new IntakeUpDown(false, 1.0)); //2.8
		//AddSequential(new IntakeForwardBack(false, 2.7));

		printf("AutonomousCommand::AutonomousCommand() - schedule ReleaseCatapultCommand2\n");
		AddSequential(new ReleaseCatapultCommand2(
			1.0, 
			.188
		));

		printf("AutonomousCommand::AutonomousCommand() - schedule ResetCatapultCommand()\n");
		AddSequential(new ResetCatapultCommand());	
	}
}
