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
	double m_timeout;
public:
	IntakeUpDown(bool, double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
