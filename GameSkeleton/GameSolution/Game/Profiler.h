#ifndef _PROFILER_H_
#define _PROFILER_H_


#include <vector>
#include <cassert>
#include <fstream>

using std::ofstream;
using std::ios;
using std::vector;


class _declspec(dllexport) Profiler
{
private:
	const char* fileName;
	unsigned int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	struct ProfileCategory
	{
		const char* name;
		vector<float> sample;
	}; 
	vector<ProfileCategory> categories;
public:
	void addEntry(const char* category, float time);
	void newFrame();
	void shutdown();
	void initialize(const char* fileName);
};

#endif