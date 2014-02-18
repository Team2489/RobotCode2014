#ifndef VISIONCLIENT_H
#define VISIONCLIENT_H

#include "Task.h"
#include "Client.h"

class VisionClient
{
public:
	VisionClient(void);
	virtual ~VisionClient();
	void Stop();
	void Start();
	int GetState(double *d, int *dynamic_on);

private:
	void Run();
	void UpdateState(int r,  double d, int dstate);
	static void MainLoop(void *);
	
	TCPClient *client;
	
	bool m_enabled; // We are running
	Task *m_task; // task doing the round-robin communication
	SEM_ID m_semaphore; // synchronize access

	// VisionClient last retrieved state
	double m_distance;
	int m_dynamic_on;

	int m_retval; // status of last state retrieval; 0 - success
};
#endif /* VISIONCLIENT_H */
