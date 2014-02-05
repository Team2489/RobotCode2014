#ifndef TIMEOUT_H
#define TIMEOUT_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author sasha
 */
class Timeout: public CommandBase {
private:
	double m_timeout;
public:
	Timeout(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
