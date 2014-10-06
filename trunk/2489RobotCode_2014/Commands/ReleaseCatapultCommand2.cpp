#include "ReleaseCatapultCommand2.h"

ReleaseCatapultCommand2::ReleaseCatapultCommand2(float a_power, float a_time):
	m_CatapultRunTask(NULL),
	m_TaskDone(false),
	m_power(a_power),
	m_time(0),
	m_inputTime(a_time)
{
	// Use requires() here to declare subsystem dependencies
	Requires(catapult);
	Requires(intake);
}

ReleaseCatapultCommand2::~ReleaseCatapultCommand2()
{
	deleteTask();
}

void ReleaseCatapultCommand2::CatapultRunProc(ReleaseCatapultCommand2* a_ptr)
{
//	printf("CatapultRunProc is working\n");
	catapult->RunCatapultMotors(a_ptr->m_power);
	Wait(a_ptr->m_time);
	catapult->RunCatapultMotors(0);
//	printf("CatapultRunProc ended\n");
	a_ptr->m_TaskDone = true;
}

void ReleaseCatapultCommand2::deleteTask()
{
	if(m_CatapultRunTask != NULL) {
		m_CatapultRunTask->Stop();
		delete m_CatapultRunTask;
		m_CatapultRunTask = NULL;
	}
	m_TaskDone = true;
}


// Called just before this Command runs the first time
void ReleaseCatapultCommand2::Initialize() {
//	printf("ReleaseCatapultCommand::Initialize()\n");
	deleteTask();
	m_TaskDone = false;
	m_time = m_inputTime;
	
}

// Called repeatedly when this Command is scheduled to run
void ReleaseCatapultCommand2::Execute() {
/*	printf("ReleaseCatapultCommand::Execute() - power=%f, duration=%f, dial=%f\n", 
			m_power, 
			m_time,
			0.0
	);*/
	if(!m_TaskDone) {
		if(m_CatapultRunTask == NULL) {
			m_CatapultRunTask = new Task("CatapultRun", (FUNCPTR)CatapultRunProc);
			m_CatapultRunTask->Start((uint32_t)this);
		}
	}
}


// Make this return true when this Command no longer needs to run execute()
bool ReleaseCatapultCommand2::IsFinished() {
//	printf("ReleaseCatapultCommand::IsFinished()\n");
	return m_TaskDone;
}

// Called once after isFinished returns true
void ReleaseCatapultCommand2::End() {
//	printf("ReleaseCatapultCommand::End()\n");
	deleteTask();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseCatapultCommand2::Interrupted() {
//	printf("ReleaseCatapultCommand::Interrupted()\n");
	End();
}
