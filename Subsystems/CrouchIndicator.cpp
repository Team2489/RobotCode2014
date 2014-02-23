#include "CrouchIndicator.h"
#include "../Robotmap.h"
#include "../Commands/CrouchIndicatorCommand.h"

CrouchIndicator::CrouchIndicator() : Subsystem("CrouchIndicator") {
	
}
    
void CrouchIndicator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CrouchIndicatorCommand());
}	


void CrouchIndicator::SetValue(float a_value) {

	float val = 1-a_value;
	int led = 0;
	if (val > 0) {			//1 light
		led = 1;
	}
	if (val > 0.125) {		//2 light
		led = 3;
	}
	if (val > 0.25) { 		//3 lights
		led = 7;
	}
	if (val > 0.375) {		//4 lights
		led = 15;
	}
	if (val > 0.5) {		//5 lights
		led = 31;
	}
	if (val > 0.625) {		//6 light
		led = 63;
	}
	if (val > 0.75) {		//7 lights
		led = 127;
	}
	if (val > 0.875) {		//8 lights
		led = 255;
	}
	
	DriverStation::GetInstance()->GetEnhancedIO().SetLEDs(~led); 

}

