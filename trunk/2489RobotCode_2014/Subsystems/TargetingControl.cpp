// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "TargetingControl.h"
#include "../Robotmap.h"
TargetingControl::TargetingControl() : Subsystem("TargetingControl") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	m_lightControl = new Relay(MODULE1NUM, 7);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	m_lightControl->Set(Relay::kReverse);
	vc = new VisionClient();
	vc->Start();
}
    
void TargetingControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
double TargetingControl::getDistance() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	double ha;
	double va;
	double d;
	double s;
	vc->GetState(&ha, &va, &d, &s);
    cout  << "targetting d = " << d << endl;
	return d;
}
