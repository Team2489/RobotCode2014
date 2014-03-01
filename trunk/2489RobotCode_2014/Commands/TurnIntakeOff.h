#ifndef TURNINTAKEOFF_H
#define TURNINTAKEOFF_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class TurnIntakeOff: public CommandBase 
{

public:
	TurnIntakeOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
