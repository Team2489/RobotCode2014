#ifndef TurnWithVision_H
#define TurnWithVision_H

#include "Commands/CommandGroup.h"
#include "Timeout.h"
#include "TurnAngle.h"

/**
 *
 *
 * @author sasha
 */
class TurnWithVision: public CommandGroup {
private:
	TurnAngle *turning;
public:	
	TurnWithVision();
	virtual void Initialize();
};

#endif
