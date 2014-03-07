// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
#include"Commands/TurnVarAngle.h"
#include"Commands/LightControl.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveBack.h"
#include "Commands/DriveBackAndForth.h"
#include "Commands/DriveForward.h"
#include "Commands/DriveInSquare.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/LightControl.h"
#include "Commands/RunTest.h"
#include "Commands/TurnAngle.h"
#include "Commands/TurnLeft.h"
#include "Commands/TurnRight.h"
#include "Commands/RunCatapultTest.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftGear.h"
#include "Commands/ShiftUp.h"
#include "Commands/DriveDistanceCommand.h"
#include "Commands/IntakeForwardBack.h"
#include "Commands/IntakeUpDown.h"
#include "Commands/RobotStay.h"
#include "Commands/ReleaseCatapultCommand.h"
#include "Commands/ResetCatapultCommand.h"
#include "Commands/ShootBallIntoGoalGroup.h"
#include "Commands/LaunchBallOverTrussGroup.h"
const double OI::PotRange = 3.2;
OI::OI():
		m_EasyButton(1)
{
	// Process operator interface input here.
	m_leftStick = new Joystick(2);
	m_rightStick = new Joystick(1);
	m_gameStick = new Joystick(3);

	
    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("RunTest", new RunTest());
	SmartDashboard::PutData("DriveBackAndForth", new DriveBackAndForth());
	SmartDashboard::PutData("DriveInSquare", new DriveInSquare());

	SmartDashboard::PutData("TurnVarAngle", new TurnVarAngle());
	screen = DriverStationLCD::GetInstance();
//	m_enhancedIO = DriverStation::GetInstance()->GetEnhancedIO()
	
	m_rightTrigger = new JoystickButton(m_rightStick, 1);
	m_leftTrigger = new JoystickButton(m_leftStick, 1);

	m_rightButton2 = new JoystickButton(m_rightStick, 2);
	m_rightButton3 = new JoystickButton(m_rightStick, 3);
	m_rightButton4 = new JoystickButton(m_rightStick, 4);
	m_rightButton5 = new JoystickButton(m_rightStick, 5);
	m_rightButton6 = new JoystickButton(m_rightStick, 6);
	m_rightButton7 = new JoystickButton(m_rightStick, 7);
	m_rightButton8 = new JoystickButton(m_rightStick, 8);
	m_rightButton9 = new JoystickButton(m_rightStick, 9);
	m_rightButton10 = new JoystickButton(m_rightStick, 10);
	m_rightButton11 = new JoystickButton(m_rightStick, 11);
	
	m_leftButton3 = new JoystickButton(m_leftStick, 3);
	m_leftButton4 = new JoystickButton(m_leftStick, 4);
	m_leftButton5 = new JoystickButton(m_leftStick, 5);
	m_leftButton6 = new JoystickButton(m_leftStick, 6);
	m_leftButton7 = new JoystickButton(m_leftStick, 7);
	m_leftButton8 = new JoystickButton(m_leftStick, 8);
	m_leftButton9 = new JoystickButton(m_leftStick, 9);
	m_leftButton10 = new JoystickButton(m_leftStick, 10);
	/*
	 *  1 -- X
		2 -- A
		3 -- B
		4 -- Y
		5 -- LB
		6 -- RB
	 	7 -- LT
		8 -- RT
	 */
	
	m_gameButton1 = new JoystickButton(m_gameStick, 1);
	m_gameButton2 = new JoystickButton(m_gameStick, 2);
	m_gameButton3 = new JoystickButton(m_gameStick, 3);
	m_gameButton4 = new JoystickButton(m_gameStick, 4);
	m_gameButton5 = new JoystickButton(m_gameStick, 5);
	m_gameButton6 = new JoystickButton(m_gameStick, 6);
	m_gameButton7 = new JoystickButton(m_gameStick, 7);
	m_gameButton8 = new JoystickButton(m_gameStick, 8);
	
	//assign events to buttons
	m_rightButton8->WhenPressed(new LightControl(true));
	m_rightButton9->WhenPressed(new LightControl(false));

	m_gameButton1->WhenPressed(new LaunchBallOverTrussGroup());
	m_gameButton4->WhenPressed(new ShootBallIntoGoalGroup());
	m_gameButton5->WhileHeld(new IntakeForwardBack(false, 0.2));
	m_gameButton7->WhileHeld(new IntakeForwardBack(true, 0.2));
	m_gameButton6->WhenPressed(new IntakeUpDown(true));
	m_gameButton8->WhenPressed(new IntakeUpDown(false));
	
	m_leftTrigger->WhenPressed(new ShiftGear());
//	m_leftButton7->WhenPressed(new RobotStay(5.0));
	
	//Testing only: Drive forward 10 inches at 0.5 power level
//	m_leftButton7->WhenPressed(new DriveDistanceCommand(200, 0.5)); 
//	m_leftButton8->WhenPressed(new ResetCatapultCommand);
	
	m_EasyButton.WhenPressed(new ShootBallIntoGoalGroup());
}
 
Joystick* OI::getm_leftStick() {
	return m_leftStick;
}
Joystick* OI::getm_rightStick() {
	return m_rightStick;
}
float OI::getCrouch(){
	float crouch;
	crouch = m_rightStick->GetZ();
	crouch = 1-crouch;	
	crouch = crouch/2;
	return crouch;
}

bool OI::getReverseDirection() {
	return (DriverStation::GetInstance()->GetEnhancedIO().GetDigital(12) == 1);
}


void OI::printCrouch(){
	double crouch = getCrouch();
	screen->PrintfLine(DriverStationLCD::kUser_Line1, "Crouch: %f", crouch);

}
void OI::printAngle(){
	screen->PrintfLine(DriverStationLCD::kUser_Line2, "Bngle: %f", CommandBase::chassis->m_gyro->PIDGet()*180);
}
OI::AutonomousVariant OI::getAutonomousVariant(){
	OI::AutonomousVariant ret = AV_NONE;
	
	
	if (!(DriverStation::GetInstance()->GetEnhancedIO().GetDigital(2)))
	{
		ret = AV_2;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(4)){
		ret = AV_4;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(6)){
		ret = AV_6;
	}else if (!DriverStation::GetInstance()->GetEnhancedIO().GetDigital(8)){
		ret = AV_8;
	}
	
	return ret;
	
}
void OI::printVariant(){
	screen->PrintfLine(DriverStationLCD::kUser_Line6, "Variant: %d", getAutonomousVariant());
}
//#define NOENCHANCEDIO 1
float OI::getCatapultSpeed(){
	float catapultspeed;
#ifdef NOENCHANCEDIO
	catapultspeed = m_leftStick->GetZ();
	catapultspeed = 1-catapultspeed;
	catapultspeed = catapultspeed/2;
#else
	catapultspeed = DriverStation::GetInstance()->GetAnalogIn(2)/PotRange;
	catapultspeed = round(catapultspeed, 0.01);
#endif
	return catapultspeed;	
}

float OI::getCatapultDuration(){
	return 0.4 * getCatapultSpeed();
}


void OI::printTargeting(){
	double d;
	int dstate;
	int ret = CommandBase::targetingControl->vc->GetState(&d, &dstate);
	if (ret == 0){
		if(dstate){
			screen->PrintfLine(DriverStationLCD::kUser_Line1,"Dynamic is on");
		}else{
			screen->PrintfLine(DriverStationLCD::kUser_Line1,"Dynamic is off");
		}
	}
	else{
		screen->PrintfLine(DriverStationLCD::kUser_Line1, "Nothing, ret = %d", ret);
	}
}


void OI::printDurationValue(){
	screen->PrintfLine(DriverStationLCD::kUser_Line3, "Duration: %f", getCatapultDuration());
}

void OI::UpdateScreen(){
	screen->UpdateLCD();
}
