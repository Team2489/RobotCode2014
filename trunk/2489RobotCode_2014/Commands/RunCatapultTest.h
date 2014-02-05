#ifndef RUNCATAPULTTEST_H
#define RUNCATAPULTTEST_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Sasha
 */
class RunCatapultTest: public CommandBase {
private:
	float m_speed;
	float m_timeout;
	bool m_varspeed;
public:
	RunCatapultTest(float, float);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
