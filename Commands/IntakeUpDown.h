#ifndef INTAKEUPDOWN_H
#define INTAKEUPDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class IntakeUpDown: public CommandBase {
private:
	bool intakeIsUp;
	bool commandIsFinished;
public:
	IntakeUpDown(bool);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
