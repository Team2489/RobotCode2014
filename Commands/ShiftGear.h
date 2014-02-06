#ifndef SHIFTGEAR_H
#define SHIFTGEAR_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class ShiftGear: public CommandBase {
public:
	ShiftGear();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
