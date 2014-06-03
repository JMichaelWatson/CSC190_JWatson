#ifndef _PORFILER_H_
#define _PORFILER_H_


#include "hr_time.h"
#include "Engine.h"
#include "Core.h"
#include <vector>
#include <fstream>

using std::vector;
using std::fstream;

class Porfiler
{
private:
	vector<float> shipDraw;//1
	vector<float> shipUpdate;//2
	vector<float> bulletDraw;//3
	vector<float> bulletUpdate;//4
	vector<float> effectDraw;//5
	vector<float> effectUpdate;//6

public:
	void add(int num, float info);
	void close();
};


#endif
