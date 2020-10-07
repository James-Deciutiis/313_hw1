#include <iostream>
#include <string>
using namespace std;

class RandomStringArray
{
private:
	int SIZE;
	string* array;
public:
	//default constructor
	RandomStringArray(){SIZE = 5000, array = new string[5000]; cout<<"Initialized with default constructor"<<endl;}
	//parameter constuctor
	RandomStringArray(int S) : SIZE(S), array(new string[S]){}
	
	//destructor
	~RandomStringArray(){delete []array;}
	
	//copy constructor
	RandomStringArray(const RandomStringArray& rhs){
		SIZE = rhs.SIZE;
		array = rhs.array;
	}

	//move constructor
	RandomStringArray(RandomStringArray&& rhs) noexcept:
		array(nullptr),
		SIZE(0)
	{
		array = rhs.array;
		SIZE = rhs.SIZE;

		//kill rhs data
		rhs.array = nullptr;
		rhs.SIZE = 0;
	}

	//operator=
	RandomStringArray& operator=(RandomStringArray& rhs) noexcept
	{
		cout<< "in operator= "<< endl;
		if(this != &rhs){
			delete array;
			array = rhs.array;
			SIZE = rhs.SIZE;

			rhs.array = nullptr;
			rhs.SIZE = 0;
		}
		return *this;
	}
	
	//populates the array with random ascii value from [32 - 126]
	string randAscii(){
		return "a" + (rand() % (94 - 1));
	}

	void fillArray(){
		for(int i = 0; i < SIZE; i++){
			array[i] = randAscii();
		}
	}

	//getters
	int getSize(){return SIZE;}
	string* getArray(){return array;}
};




