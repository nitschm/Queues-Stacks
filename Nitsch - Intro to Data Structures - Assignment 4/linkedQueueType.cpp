#include <iostream>
#include <cassert>
#include "linkedQueueType.h"

bool linkedQueueType::isEmptyQueue() const
{
	return(queueFront == NULL);
}

void linkedQueueType::initializeQueue()
{
	typeNode* temp;

	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront = queueFront->link;

		delete temp;
	}

	queueRear = NULL;
}

void linkedQueueType::addQueue(const char& newItem)
{
	typeNode* newNode;
	newNode = new typeNode;

	newNode->info = newItem;
	newNode->link = NULL;
	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	{
		queueRear->link = newNode;
		queueRear = newNode;
	}
}

char linkedQueueType::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

char linkedQueueType::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

void linkedQueueType::deleteQueue()
{
	typeNode* temp;

	if (!isEmptyQueue())
	{
		temp = queueFront;
		queueFront = queueFront->link;

		delete temp;

		if (queueFront == NULL)
		{
			queueRear = NULL;
		}
	}
	else
	{
		cout << "Cannot remove from an empty queue" << endl;
	}
}

linkedQueueType::linkedQueueType()
{
	queueFront = NULL;
	queueRear = NULL;
}

linkedQueueType::~linkedQueueType()
{
	initializeQueue();
}
