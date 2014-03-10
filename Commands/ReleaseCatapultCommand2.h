#ifndef RELEASECATAPULTCOMMAND2_H
#define RELEASECATAPULTCOMMAND2_H

#include "../CommandBase.h"
//Uses sensors 
/**
 *
 *
 * @author olga
 */
class ReleaseCatapultCommand2: public CommandBase {
private:
	Task* m_CatapultRunTask;
	bool m_TaskDone;
	float m_power;
	float m_time;
	float m_inputTime;
	
	static void CatapultRunProc(ReleaseCatapultCommand2* a_ptr);
	void deleteTask();
	
public:
	///\brief
	///\params
	///   a_power - power to apply to motors, values -1.0 to 1.0
	///   a_time - time to apply power, value in seconds
	ReleaseCatapultCommand2(float a_power, float a_time); 
	
	virtual ~ReleaseCatapultCommand2(); 
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
