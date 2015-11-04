#ifndef _OAK_H
#define _OAK_H

#include "tree.h"
#include <exception>

class OakEmptyException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "This tree is empty, stupid!";
	}
};

class Oak : public Tree
{
public:
	int top() const;
	void pop();
};

#endif

