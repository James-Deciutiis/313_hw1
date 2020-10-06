#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>
#include "randomIntArray.h"
#include "randomIntVector.h"
#include "randomStringArray.h"
#include "randomStringVector.h"
using namespace std;

class TimeTrial
{
private:
	int _trials;
public:
	//default constructor
	TimeTrial(){_trials = 10; cout<<"initialized with default constructor"<<endl;}
	//parameter contructor
	TimeTrial(int t) : _trials(t){cout<<"initialized with parameters"<<endl;}
	
	void partA(RandomIntArray a, RandomIntVector v){
		cout<<"Filling array with " << a.getSize() << " random numbers"<<endl;
		auto start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < a.getSize(); j++){
				a.fillArray();
			}
		}
		auto end = chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took " << elapsed.count() << " milliseconds." << endl;
		
		
		cout<<"Filling vector with " << v.getSize() << " random numbers"<<endl;
		start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < v.getSize(); j++){
				v.fillVector();
			}
		}
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took " << elapsed.count() << " milliseconds." << endl;
	}

	void partB(RandomStringArray a, RandomStringVector v){
		
		cout<<"Filling array with " << a.getSize() << " random strings"<<endl;
		auto start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < a.getSize(); j++){
				a.fillArray();
			}
		}
		auto end = chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took " << elapsed.count() << " milliseconds." << endl;
		
		
		cout<<"Filling vector with " << a.getSize() << " random strings"<<endl;
		start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < v.getSize(); j++){
				v.fillVector();
			}
		}
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took " << elapsed.count() << " milliseconds." << endl;
	}

	void partC(RandomStringArray a, RandomStringVector v){
		
		cout<<"Filling array with " << a.getSize() << " random strings using move semantics"<<endl;
		a.fillArray();
		auto start = chrono::steady_clock::now();
		RandomStringArray b = a;
		auto end = chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "It took " << elapsed.count() << " microseconds." << endl;
		
		cout<<"Filling vector with " << v.getSize() << " random strings using move semantics"<<endl;
		v.fillVector();
		start = chrono::steady_clock::now();
		RandomStringVector w = v;
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "It took " << elapsed.count() << " microseconds." << endl;
	}
};

