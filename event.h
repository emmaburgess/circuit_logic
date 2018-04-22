#ifndef EVENT_HEADER
#define EVENT_HEADER
#include<string>
#include<iostream>
#include "gate.h"
using namespace std;

class Event {
public:
	Event(string nameref, int timeref, int valref, int sortcountref);
	Event();

	void setEventName(string ref);
	void setTime(int ref);
	void setEventValue(int ref);
	void setSortCount(int ref);

	int getEventValue();
	int getEventTime();
	int getSortCount();

private:
	string name;
	int time;
	int value;
	int sortcount;

};
#endif

