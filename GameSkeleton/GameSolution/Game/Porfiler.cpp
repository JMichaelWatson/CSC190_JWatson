#include "Porfiler.h"


void Porfiler::add(int num, float info){
	if(num == 1){
		shipDraw.push_back(info);
	}else if(num == 2){
		shipUpdate.push_back(info);
	} else if(num == 3){
		bulletDraw.push_back(info);
	} else if(num == 4){
		bulletUpdate.push_back(info);
	} else if(num == 5){
		effectDraw.push_back(info);
	} else if(num == 6){
		effectUpdate.push_back(info);
	}
}

void Porfiler::close(){
	fstream fS;
	fS.open("profiler.csv", std::ios::out, std::ios::app);
	fS <<"Ship Draw, Ship Update";
	for(int x = 0; x < 1000; x++){
		fS << shipDraw[x] << "," << shipUpdate[x];
	}

}