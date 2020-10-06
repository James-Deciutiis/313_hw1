#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RandomIntVector
{
private:
	int SIZE;
	vector<int> _vector;
public:
	RandomIntVector(){SIZE = 5000, _vector = vector<int>(SIZE); cout<<"initialized with default constructor"<<endl;}
	RandomIntVector(int s) : SIZE(s), _vector(vector<int>(SIZE)) {cout<<"initialized with parameters"<<endl;}
	
	//destructor
	~RandomIntVector(){ _vector.clear(); }
	
	//copy constructor
	RandomIntVector(const RandomIntVector &rhs){
		SIZE = rhs.SIZE;
		_vector = rhs._vector;
	}

	//move constructor
	RandomIntVector(RandomIntVector &&rhs) noexcept:
		SIZE(0),
		_vector({})
	{
		SIZE = rhs.SIZE;
		_vector = rhs._vector;

		rhs.SIZE = 0;
		rhs._vector.clear();
	}

	//operator=
	RandomIntVector& operator=(RandomIntVector &rhs) noexcept
	{
		if(this != &rhs){
			_vector.clear();
			_vector = rhs._vector;
			SIZE = rhs.SIZE;

			rhs._vector.clear();
			rhs.SIZE = 0;
		}

		return *this;
	}
	
	void fillVector(){
		for(int i = 0; i < SIZE; i++){
			_vector[i] = rand();
		}
	}

	vector<int> getVector(){return _vector;}
	int getSize(){return SIZE;}
};
	
