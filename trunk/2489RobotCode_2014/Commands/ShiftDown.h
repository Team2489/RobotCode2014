#ifndef SHIFTDOWN_H
#define SHIFTDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class ShiftDown: public CommandBase {
public:
	ShiftDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
