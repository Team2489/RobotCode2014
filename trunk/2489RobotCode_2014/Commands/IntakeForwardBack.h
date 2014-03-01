#ifndef INTAKEFORWARDBACK_H
#define INTAKEFORWARDBACK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class IntakeForwardBack: public CommandBase {
private:
	bool spit;
	float m_timeout;
public:
	IntakeForwardBack(bool, double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
