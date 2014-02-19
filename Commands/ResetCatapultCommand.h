#ifndef RESETCATAPULTCOMMAND_H
#define RESETCATAPULTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author olga
 */
class ResetCatapultCommand: public CommandBase {

public:
	ResetCatapultCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
