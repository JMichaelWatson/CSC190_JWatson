#ifndef _TIMER_H_
#define _TIMER_H_

#include<Windows.h>

class Clock
{
	LARGE_INTEGER timeFrequency;
	LARGE_INTEGER timelastFrame;
	LARGE_INTEGER detlaLastFrame;
	float deltaTime;
public:
	bool initialize();
	bool shutdown();
	void newFrame();
	float timeElaspedLastFrame() const;
}; 
#endif