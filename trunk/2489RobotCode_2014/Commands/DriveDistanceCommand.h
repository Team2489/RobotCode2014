#ifndef DRIVEDISTANCECOMMAND_H
#define DRIVEDISTANCECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author olga
 */
class DriveDistanceCommand: public CommandBase 
{
private:
	int m_InitialValueRight;
	int m_InitialValueLeft;
	float m_distance;
	float m_power;
	int m_encoderTicksToTravel;
public:
	DriveDistanceCommand(float distance, float power);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
