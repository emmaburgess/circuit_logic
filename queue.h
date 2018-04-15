#include<string>
#include<iostream>
#include<vector>
#include "event.h"
using namespace std;

class Queue {
public:
	
	//NOT A NECESSARY CLASS
	//All that is needed is:
	/*
	priority-queue<Event> pqueue;
	*/
	
	//Set vector contents in order
	void order();
	void InsertEvent(Event &ref);
private:
	//Priority Queue
	vector<Event>pqueue;

};
