#include "TurnWithVision.h"

TurnWithVision::TurnWithVision() {
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
	
	turning = new TurnAngle(0, TURNANGLETOLERENCE, TURNANGLEDELTA, TURNANGLEZONE, COMPENSATION, 1.0);

	AddSequential(turning);

	
}

void TurnWithVision::Initialize(){
	double d, ha, va, s;
	int ret = CommandBase::targetingControl->vc->GetState(&ha, &va, &d, &s);
	//cout << "TurnWithVision::Initialize: ret = " << ret << endl;
	//cout << "TurnWithVision::Initialize: ha = " << ha << endl;
	//cout << "TurnWithVision::Initialize: va = " << va << endl;
	//cout << "TurnWithVision::Initialize: d = " << d << endl;
	//cout << "TurnWithVision::Initialize: s = " << s << endl;
	if (ret == 0) {
		//cout << "Setting ha = " << ha << endl;
		turning->SetAngle(ha);

	} else {
		// when we set all to 0 we effectively disable all commands
		turning->SetAngle(0);
		
	}
}
