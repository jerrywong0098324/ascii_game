#ifndef _TIMER_H
#define _TIMER_H

// Used to get time between frames. Time in ms

#include <Windows.h>
#include "Singleton.h"

class StopWatch
{
public:
	StopWatch();
	~StopWatch();

	double GetDeltaTime();
	void StartTimer();
	void WaitUntil(long long time);

private:

	LARGE_INTEGER freq;
	LARGE_INTEGER prevTime, currTime;
	UINT wTimerRes;

	double LiToSec(LARGE_INTEGER& time);
};

#endif