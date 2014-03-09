#ifndef REVERSECHASSISDIRECTIONCONTROLCOMMAND_H
#define REVERSECHASSISDIRECTIONCONTROLCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author olga
 */
class ReverseChassisDirectionControlCommand: public CommandBase {
private:
	bool m_reverseDirection;	// true is reverse
								//false is to previous or initial position

public:
	ReverseChassisDirectionControlCommand(bool a_value);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
