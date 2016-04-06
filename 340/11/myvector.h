#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

template <typename T> class MyVector
{
public:
	MyVector();
	void push_back(const T& value);
	T& operator[](int index);
	int size() const;

private:
	T* array;
	int currentSize;
	int capacity;
};

#endif

