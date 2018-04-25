#include<string>
#include<iostream>
#include<vector>
#include "event.h"
using namespace std;

class Queue {
public:
	//Set vector contents in order
	void order();
	void InsertEvent(Event &ref);
private:
	//Priority Queue
	vector<Event>pqueue;

};