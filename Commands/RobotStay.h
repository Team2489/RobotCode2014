#ifndef ROBOTSTAY_H
#define ROBOTSTAY_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class RobotStay: public CommandBase {
public:
	RobotStay(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
