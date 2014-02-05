#include "TurnVarAngle.h"

TurnVarAngle::TurnVarAngle()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	mycommand = new TurnAngle(0, TURNANGLETOLERENCE, TURNANGLEDELTA, TURNANGLEZONE, COMPENSATION);
	AddSequential(mycommand);
}

// Called just before this Command runs the first time
void TurnVarAngle::Initialize()
{
	
	double angle = SmartDashboard::GetNumber("angle");
	mycommand->SetAngle(angle);
}
