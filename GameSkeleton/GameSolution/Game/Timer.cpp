#include "Timer.h"

bool Clock::initialize(){

	if(! QueryPerformanceFrequency(&timeFrequency))
		return false;
	QueryPerformanceCounter(&timelastFrame);
	return true;

}

bool Clock::shutdown(){ return true; }

void Clock::newFrame(){
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - timelastFrame.QuadPart;
	deltaTime = ((float)delta.QuadPart) / timeFrequency.QuadPart;
	timelastFrame.QuadPart = thisTime.QuadPart;
}

float Clock::timeElaspedLastFrame() const{

	return deltaTime;
}


