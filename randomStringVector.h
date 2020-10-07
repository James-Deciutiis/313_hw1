#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RandomStringVector
{
private:
	int SIZE;
	vector<string> _vector;
public:
	RandomStringVector(){SIZE = 5000, _vector = vector<string>(SIZE); cout<<"initialized with default constructor"<<endl;}
	RandomStringVector(int s) : SIZE(s), _vector(vector<string>(SIZE)) {}
	
	//destructor
	~RandomStringVector(){ _vector.clear(); }
	
	//copy constructor
	RandomStringVector(const RandomStringVector &rhs){
		SIZE = rhs.SIZE;
		_vector = rhs._vector;
	}

	//move constructor
	RandomStringVector(RandomStringVector &&rhs) noexcept:
		SIZE(0),
		_vector({})
	{
		SIZE = rhs.SIZE;
		_vector = rhs._vector;

		rhs.SIZE = 0;
		rhs._vector.clear();
	}

	//operator=
	RandomStringVector& operator=(RandomStringVector &rhs) noexcept
	{
		cout<< "in operator= "<< endl;
		if(this != &rhs){
			_vector.clear();
			_vector = rhs._vector;
			SIZE = rhs.SIZE;

			rhs._vector.clear();
			rhs.SIZE = 0;
		}

		return *this;
	}
	
	//populates the array with random ascii value from [32 - 126]
	string randAscii(){
		return "a" + (rand() % (94 - 1));
	}

	void fillVector(){
		for(int i = 0; i < SIZE; i++){
			_vector[i] = randAscii();
		}
	}

	vector<string> getVector(){return _vector;}
	int getSize(){return SIZE;}
};
	
