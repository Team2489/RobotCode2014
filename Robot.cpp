// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
int vision_mode = VISION_COLLECT_IMAGES_OFF;
Robot::Robot():
	autonomousCommand(NULL),
	teleopCommand(NULL)
{
	printf("Robot::Robot()\n");
}

void Robot::RobotInit() {
	CommandBase::init();
	// instantiate the command used for the autonomous periodS
	printf("Robot::RobotInit()\n");
	teleopCommand = new DriveWithJoysticks();
}

void Robot::AutonomousInit() {
	printf("Robot::AutonomousInit()\n");
	vision_mode = VISION_COLLECT_IMAGES_ON;
	if (autonomousCommand != NULL) {
		delete autonomousCommand;
		autonomousCommand = NULL;
	}

	autonomousCommand = new AutonomousCommand();
	autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	CommandBase::oi->printVariant();
	CommandBase::oi->UpdateScreen();
	if (autonomousCommand != NULL){
		Scheduler::GetInstance()->Run();
	}
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	vision_mode = VISION_COLLECT_IMAGES_OFF;
	if(autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	
	teleopCommand->Start();
}
	
void Robot::TeleopPeriodic() {
	//cout << "TeleopPeriodic run" << endl;
	if (teleopCommand != NULL){
		Scheduler::GetInstance()->Run();
		//oi->printCrouch();
		CommandBase::oi->printTargeting();
		CommandBase::oi->printDurationValue();
		CommandBase::oi->printAngle();
		CommandBase::oi->printEncoderValues();
		CommandBase::oi->UpdateScreen(); //Don't put print out below this line
		// oi->printVariant();
	//	cout << "sensor = " << Robot::shooter->pistonSensor->Get() << endl;
	//	chassis->getAccel();
	//	shooter->getAccel();
	//	cout << "Shooter Angle: " << shooter->getAngle() << endl; 
	}
}

START_ROBOT_CLASS(Robot);
