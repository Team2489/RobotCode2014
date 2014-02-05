#include "VisionClient.h"
#include <Timer.h>
#include <iostream>

static const unsigned int debug = 0;

using namespace std;

void VisionClient::MainLoop(void *ptr)
{
	if (debug) {
		cout << "VisionClient::MainLoop" << endl;
	}
	VisionClient *c = (VisionClient *) ptr;
	c->Run();
}

void VisionClient::Run(void)
{
	double va;
	double ha;
	double d;
	double s;
	int r;

	if (debug) {
		cout << "VisionClient::Run m_enabled = " << m_enabled << endl;
	}
	while (m_enabled)
	{
		// supposedly we are reading these values from network
		// insert real code here; note this code may block on
		// network operations
				directions direc;
		
		if (client->IsConnected()){
			if (debug) {
				cout << "Client is reading." << endl;
			}
			client->Send(TCPClient::PULL);
			client->Receive(&direc);
		}
		else {
			if (debug) {
				cout << "Client is connecting." << endl;
			}
			client->Connect();
			direc.status = -1;
		}
		
		r = direc.status;
		va = direc.vert_angle;
	    ha = direc.horiz_angle;
	    d = direc.dist;
	    s = direc.shooter_speed;

	    UpdateState(r, va, ha, d, s);
	    if (debug) {
	    	cout  << "Run r = " << r << endl;
	    	cout  << "Run d = " << d << endl;
	    	cout  << "Run s = " << s << endl;
	    	cout  << "Run va = " << va << endl;
	    	cout  << "Run ha = " << ha << endl;
	    }
		Wait(0.1);
	}
	if (debug) {
		cout << "VisionClient::Run Exiting" << endl;
	}
}

void VisionClient::Start(void)
{
	if (debug) {
		cout << "VisionClient::Start" << endl;
	}
	m_enabled = true;
	m_task->Start((UINT32)this);
}


void VisionClient::Stop(void)
{
	m_enabled = false;
}

VisionClient::VisionClient(void)
{
	if (debug) {
		cout << "VisionClient::VisionClient" << endl;
	}
	m_enabled = true;
	m_semaphore = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	m_task = new Task("2489VisionClient", (FUNCPTR)MainLoop);
	client = new TCPClient("10.24.89.15");
	cout << "VisionClient::VisionClient: m_enabled = " << m_enabled << endl;
}


void VisionClient::UpdateState(int r, double ha, double va, double d, double s)
{
	if (debug) {
		cout << "VisionClient::UpdateState" << endl;
	}
	semTake(m_semaphore, WAIT_FOREVER);
	{
		// really quick - just update our state
		m_horizontalAngle = ha;
		m_verticalAngle = va;
		m_distance = d;
		m_shooter_speed = s / 1000.0;
		m_retval = r;
	}
	semGive(m_semaphore);
}

int VisionClient::GetState(double *ha, double *va, double *d, double *s)
{
	if (debug) {
		cout << "VisionClient::GetState" << endl;
	}
	int ret;
	semTake(m_semaphore, WAIT_FOREVER);
	{
		// really quick - just get our state
		*ha = m_horizontalAngle;
		*va = m_verticalAngle;
		*d = m_distance;
		*s = m_shooter_speed;
		ret = m_retval;
	}
	semGive(m_semaphore);
	if (debug) {
		cout  << "getstate *ha = " << *ha << endl;
		cout  << "getstate *va = " << *va << endl;
		cout  << "getstate *d = " << *d << endl;
		cout  << "getstate ret = " << ret << endl;
	}
	return ret;
}


VisionClient::~VisionClient()
{
	m_task->Stop();
	m_task = NULL;
}
