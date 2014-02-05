#include "CommandBase.h"
#include "Subsystems/Chassis.h"
#include "Commands/Scheduler.h"
#include "Robotmap.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}


OI* CommandBase::oi = NULL;
Chassis* CommandBase::chassis = NULL;
Pump* CommandBase::pump = 0;
TargetingControl* CommandBase::targetingControl = 0;
Catapult* CommandBase::catapult = 0;

void CommandBase::init() {
	

	chassis = new Chassis();;
	pump = new Pump();
	targetingControl = new TargetingControl();
	catapult = new Catapult();
	oi = new OI();
}
