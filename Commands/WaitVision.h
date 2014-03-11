#ifndef WAITVISION_H
#define WAITVISION_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class WaitVision: public CommandBase {
	double m_timeout;
public:
	WaitVision(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
