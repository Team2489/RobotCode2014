#ifndef SHIFTUP_H
#define SHIFTHUP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class ShiftUp: public CommandBase {
public:
	ShiftUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
