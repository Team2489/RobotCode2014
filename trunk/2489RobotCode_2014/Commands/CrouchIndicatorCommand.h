#ifndef CROUCHINDICATORCOMMAND_H
#define CROUCHINDICATORCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author olga
 */
class CrouchIndicatorCommand: public CommandBase {
public:
	CrouchIndicatorCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
