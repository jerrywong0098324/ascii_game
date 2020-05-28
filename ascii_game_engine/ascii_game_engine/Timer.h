#ifndef _TIMER_H
#define _TIMER_H

// Used to get time between frames. Time in ms

#include <Windows.h>
#include "Singleton.h"

class Application;

class StopWatch : public Singleton<StopWatch>
{
	friend class Application;
public:
	double GetDeltaTime();
	void StartTimer();
	void WaitUntil(long long time);

private:
	// Singleton definition
	friend class Singleton<StopWatch>;
	StopWatch();
	~StopWatch();

	virtual void free_memory();

	LARGE_INTEGER freq;
	LARGE_INTEGER prevTime, currTime;
	UINT wTimerRes;

	double deltaTime;

	double LiToSec(LARGE_INTEGER& time);
	void UpdateTimer();
};

#endif