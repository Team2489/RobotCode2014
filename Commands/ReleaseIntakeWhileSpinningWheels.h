#ifndef RELEASEINTAKEWHILESPINNINGWHEELS_H
#define RELEASEINTAKEWHILESPINNINGWHEELS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vignesh
 */
class ReleaseIntakeWhileSpinningWheels: public CommandBase {
private:
	double m_timeout;
public:
	ReleaseIntakeWhileSpinningWheels(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
