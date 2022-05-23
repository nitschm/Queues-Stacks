// Nitsch - Intro to Data Structures - Assignment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "linkedQueueType.h"
#include "linkedStackType.h"
using namespace std;

int main()
{
    char ch;
    linkedQueueType queue;
    linkedStackType myStack;
    bool test = true;

    cout << "Please enter a sentence: ";
    cin.get(ch);

    cout << endl;

    while (ch != '\n')
    {
        queue.addQueue(static_cast<char>(toupper(ch)));
        myStack.push(static_cast<char>(toupper(ch)));
        cin.get(ch);
    }
    
    while (!queue.isEmptyQueue())
    {
        if (queue.front() != myStack.top())
            test = false;

        cout << queue.front();
        queue.deleteQueue();
        myStack.pop();
    }

    cout << endl;

    if (test == false)
        cout << "This sentence is not a palindrome.";
    else
        cout << "This sentence is a palindrome.";

    cout << endl;

    return 0;
}


