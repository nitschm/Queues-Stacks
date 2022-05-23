#include "linkedStackType.h"
#include <iostream>
#include <cassert>
using namespace std;

//constructor
linkedStackType::linkedStackType()
{
	stackTop = NULL;
}

//copy constructor
linkedStackType::linkedStackType(const linkedStackType& otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

linkedStackType::~linkedStackType()
{
	initializeStack();
}

const linkedStackType& linkedStackType::operator=(const linkedStackType& otherStack)
{
	if (this != &otherStack)
		copyStack(otherStack);

	return *this;
}

void linkedStackType::initializeStack()
{
	nodeType* temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}

bool linkedStackType::isEmptyStack()
{
	return (stackTop == NULL);
}

void linkedStackType::push(const char& newElement)
{
	nodeType* newNode;

	newNode = new nodeType;

	newNode->info = newElement;
	newNode->link = stackTop;
	stackTop = newNode;
}

char linkedStackType::top()
{
	assert(stackTop != NULL);
	return stackTop->info;
}

void linkedStackType::pop()
{
	nodeType* temp;

	if (stackTop != NULL)
	{
		temp = stackTop;

		stackTop = stackTop->link;

		delete temp;
	}
	else
		cout << "Cannot remove from an empty stack." << endl;
}

void linkedStackType::copyStack(const linkedStackType& otherStack)
{
	nodeType* newNode, * current, * last;

	if (stackTop != NULL)
		initializeStack();

	if (otherStack.stackTop == NULL)
		stackTop = NULL;
	else
	{
		current = otherStack.stackTop;

		stackTop = new nodeType;

		stackTop->info = current->info;
		stackTop->link = NULL;
		last = stackTop;
		current = current->link;

		while (current != NULL)
		{
			newNode = new nodeType;

			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
