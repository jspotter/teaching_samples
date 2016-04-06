#include <cstdlib>
#include "myvector.h"
using namespace std;

template <typename T>
MyVector<T>::MyVector() : currentSize(0), capacity(10) {
	array = new T[capacity];
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
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

template <typename T>
T& MyVector<T>::operator[](int index) {
	return array[index];
}

template <typename T>
int MyVector<T>::size() const {
	return currentSize;
}

