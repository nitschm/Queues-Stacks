#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H
#include <iostream>
using namespace std;

struct typeNode
{
	char info;
	typeNode* link;
};

class linkedQueueType
{
	private:
		typeNode* queueFront;
		typeNode* queueRear;
		int count;
	public:
		//const linkedQueueType& operator=(const linkedQueueType&);
		void initializeQueue();
		bool isEmptyQueue() const;
		char front() const;
		char back() const;
		void addQueue(const char& newItem);
		void deleteQueue();
		linkedQueueType();
		//linkedQueueType(const linkedQueueType& otherQueue);
		~linkedQueueType();
};

#endif