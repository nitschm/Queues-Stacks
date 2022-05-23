#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <iostream>
using namespace std;

//Creates node
struct nodeType
{
	char info;
	nodeType* link;
};

//linked list class
class linkedStackType
{
private:
	nodeType* stackTop;
	void copyStack(const linkedStackType& otherStack);
public:
	const linkedStackType& operator=(const linkedStackType&);
	void initializeStack();
	bool isEmptyStack();
	void push(const char& newElement);
	char top();
	void pop();
	linkedStackType();
	linkedStackType(const linkedStackType& otherStack);
	~linkedStackType();
};

#endif
