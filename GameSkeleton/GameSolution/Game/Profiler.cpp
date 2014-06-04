#include "Profiler.h"


void Profiler::initialize(const char* fileName){
	this ->fileName = fileName;
	frameIndex = -1;
	categoryIndex = 0;
	numUsedCategories = 0;
}

void Profiler::shutdown(){
	ofstream outStream(fileName, ios::trunc);

	for(unsigned int i = 0; i < numUsedCategories; i ++){
		outStream << categories[i].name;
		if(i+1 < numUsedCategories){
			outStream << ",";
		} else{
			outStream << '\n';
		}
	}
	
	unsigned int num_actual_frames = frameIndex;
	if(categoryIndex == numUsedCategories){
		num_actual_frames++;
	}

	for(unsigned int frame = 0; frame < num_actual_frames; frame++){
		for(unsigned int cat =0; cat < numUsedCategories; cat++){
			const ProfileCategory& p = categories[cat];
			outStream << p.sample[frame];
			if(cat+1 < numUsedCategories){
				outStream << ",";
			} else{
				outStream << '\n';
			}
		}
	}

}

void Profiler::newFrame(){
	if(frameIndex > 0){
		assert(categoryIndex == numUsedCategories);
	}
	frameIndex++;
	categoryIndex = 0;
}

void Profiler::addEntry(const char* category, float time){

	ProfileCategory& pc = categories[categoryIndex++];
	if(frameIndex == 0){
		pc.name = category;
		numUsedCategories++;
	} else{
		assert(pc.name == category && category != NULL);
		assert(categoryIndex < numUsedCategories);
	}
	categoryIndex++;
	pc.sample[frameIndex] = time;
}

