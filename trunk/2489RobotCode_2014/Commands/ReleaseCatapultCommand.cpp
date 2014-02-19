#include "ReleaseCatapultCommand.h"

ReleaseCatapultCommand::ReleaseCatapultCommand(float a_power, float a_time):
	m_CatapultRunTask(NULL),
	m_TaskDone(false),
	m_power(a_power),
	m_time(a_time)

{
	// Use requires() here to declare subsystem dependencies
	Requires(catapult);
}

ReleaseCatapultCommand::~ReleaseCatapultCommand()
{
	deleteTask();
}

void ReleaseCatapultCommand::CatapultRunProc(ReleaseCatapultCommand* a_ptr)
{
	printf("CatapultRunProc is working\n");
	catapult->RunCatapultMotors(a_ptr->m_power);
	Wait(a_ptr->m_time);
	catapult->RunCatapultMotors(0);
	printf("CatapultRunProc ended\n");
	a_ptr->m_TaskDone = true;
}

void ReleaseCatapultCommand::deleteTask()
{
	if(m_CatapultRunTask != NULL) {
		m_CatapultRunTask->Stop();
		delete m_CatapultRunTask;
		m_CatapultRunTask = NULL;
	}
	m_TaskDone = true;
}


// Called just before this Command runs the first time
void ReleaseCatapultCommand::Initialize() {
	printf("ReleaseCatapultCommand::Initialize()\n");
	deleteTask();
	m_TaskDone = false;
}

// Called repeatedly when this Command is scheduled to run
void ReleaseCatapultCommand::Execute() {
	printf("ReleaseCatapultCommand::Execute()\n");
	if(m_CatapultRunTask == NULL) {
		m_CatapultRunTask = new Task("CatapultRun", (FUNCPTR)CatapultRunProc);
		m_CatapultRunTask->Start((uint32_t)this);
	}
}


// Make this return true when this Command no longer needs to run execute()
bool ReleaseCatapultCommand::IsFinished() {
	printf("ReleaseCatapultCommand::IsFinished()\n");
	return m_TaskDone;
}

// Called once after isFinished returns true
void ReleaseCatapultCommand::End() {
	printf("ReleaseCatapultCommand::End()\n");
	deleteTask();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseCatapultCommand::Interrupted() {
	printf("ReleaseCatapultCommand::Interrupted()\n");
	End();
}
