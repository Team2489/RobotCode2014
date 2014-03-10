#ifndef INTAKEFORWARDBACK2_H
#define INTAKEFORWARDBACK2_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class IntakeForwardBack2: public CommandBase {
private:
	bool spit;
	float m_timeout;
public:
	IntakeForwardBack2(bool, double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
