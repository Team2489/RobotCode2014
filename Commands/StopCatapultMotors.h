#ifndef STOPSCATAPULTMOTORS_H
#define STOPCATAPULTMOTORS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class StopCatapultMotors: public CommandBase {
public:
	StopCatapultMotors();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
