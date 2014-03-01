#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Pump.h"
#include "Subsystems/TargetingControl.h"
#include "Subsystems/Catapult.h"
#include "Subsystems/Intake.h"
#include "Subsystems/CrouchIndicator.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
	
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Chassis* chassis;
	static Intake* intake;
	static Pump* pump;
	static TargetingControl* targetingControl;
	static Catapult* catapult;
	static CrouchIndicator* crouchIndicator;
};

#endif
