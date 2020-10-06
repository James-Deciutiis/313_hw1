#include <iostream>
using namespace std;

class RandomIntArray
{
private:
	int SIZE;
	int* array;
public:
	//default constructor
	RandomIntArray(){SIZE = 5000, array = new int[5000]; cout<<"Initialized with default constructor"<<endl;}
	//parameter constuctor
	RandomIntArray(int S) : SIZE(S), array(new int[S]){cout<<"Initialized with parameters"<<endl;}
	
	//destructor
	~RandomIntArray(){delete []array;}
	
	//copy constructor
	RandomIntArray(const RandomIntArray& rhs){
		SIZE = rhs.SIZE;
		array = rhs.array;
	}

	//move constructor
	RandomIntArray(RandomIntArray&& rhs) noexcept:
		array(nullptr),
		SIZE(0)
	{
		*array = *rhs.array;
		SIZE = rhs.SIZE;

		//kill rhs data
		rhs.array = nullptr;
		rhs.SIZE = 0;
	}

	//operator=
	RandomIntArray& operator=(RandomIntArray& rhs) noexcept
	{
		if(this != &rhs){
			delete array;
			array = rhs.array;
			SIZE = rhs.SIZE;

			rhs.array = nullptr;
			rhs.SIZE = 0;
		}
		return *this;
	}
	
	void fillArray(){
		for(int i = 0; i < SIZE; i++){
			array[i] = rand();
		}
	}

	//getters
	int getSize(){return SIZE;}
	int* getArray(){return array;}
};

