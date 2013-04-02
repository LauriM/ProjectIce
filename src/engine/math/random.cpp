#include "precompiled.h"

#include "engine/math/random.h"

void randomInit(){
	srand(time(NULL));//TODO: Change seed (2013-04-01)
}

int randomRange(int min,int max){
	return (rand() % (max-min+1)) + min;
}
