#include <iostream>
#include <vector>
#include "timeTrial.h"
using namespace std;


int main(){
	
	//parameter for TimeTrial is for the amount of trials it will do
	//final results are the average times taken over all trials
	TimeTrial trial(10);
	
	RandomIntArray ary(10000);
	RandomIntVector vect(10000);

	trial.partA(ary, vect);

	RandomStringArray strary(10000);
	RandomStringVector strvect(10000);

	trial.partB(strary, strvect);
	
	RandomStringArray strary2(10000);
	RandomStringVector strvect2(10000);

	trial.partC(strary2, strvect2);

	return 0;
}

