#include "Timer.h"

StopWatch::StopWatch()
{
	QueryPerformanceFrequency(&freq);

#define TARGET_RESOLUTION 1
	TIMECAPS tc;

	if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
	{
		// Error
	}

	wTimerRes = min(max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
	timeBeginPeriod(wTimerRes);
}

StopWatch::~StopWatch()
{
	timeEndPeriod(wTimerRes);
}

double StopWatch::LiToSec(LARGE_INTEGER& time)
{
	return ((double)time.QuadPart / (double)freq.QuadPart);
}

double StopWatch::GetDeltaTime()
{
	return deltaTime;
}

void StopWatch::UpdateTimer()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&currTime);
	time.QuadPart = currTime.QuadPart - prevTime.QuadPart;
	prevTime = currTime;
	deltaTime = LiToSec(time);
}

void StopWatch::StartTimer()
{
	QueryPerformanceCounter(&prevTime);
}

void StopWatch::WaitUntil(long long time)
{
	LARGE_INTEGER timeNow;
	LONGLONG timeElapsed;
	while (true)
	{
		QueryPerformanceCounter(&timeNow);
		timeElapsed = ((timeNow.QuadPart - prevTime.QuadPart) * 1000 / freq.QuadPart);
		if (timeElapsed > time)
			return;
		else if (time - timeElapsed > 1)
			Sleep(1);
	}
}

void StopWatch::free_memory()
{
	timeEndPeriod(wTimerRes);
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}