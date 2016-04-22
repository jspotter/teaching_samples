#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	MyVector() : currentSize(0), capacity(10) {
		array = new T[capacity];
	}

	void push_back(const T& value) {
		if (capacity == currentSize) {
			T* newArray = new T[capacity * 2];
			for (int i = 0; i < currentSize; i++) {
				newArray[i] = array[i];
			}

			delete array;
			array = newArray;
			capacity *= 2;
		}

		array[currentSize++] = value;
	}

	T& operator[](int index) {
		return array[index];
	}

	int size() const {
		return currentSize;
	}
private:
	T* array;
	int currentSize;
	int capacity;
};

int main()
{
	MyVector<int> intVector;
	MyVector<string> stringVector;

	intVector.push_back(3);
	intVector.push_back(4);

	stringVector.push_back("hi");
	stringVector.push_back("bye");

	for (int i = 0; i < intVector.size(); i++) {
		cout << intVector[i] << endl;
	}

	for (int i = 0; i < stringVector.size(); i++) {
		cout << stringVector[i] << endl;
	}

	return 0;
}

