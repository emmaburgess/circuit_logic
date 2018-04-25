#ifndef EVENT_HEADER
#define EVENT_HEADER
#include<string>
#include<iostream>
#include "gate.h"
using namespace std;
class Wire;

class Event {
public:
	Event(string nameref, int timeref, int valref, int sortcountref);
	Event();

	void setEventName(string ref);
	void setTime(int ref);
	void setEventValue(int ref);
	void setSortCount(int ref);

	Wire* getWirePTR(vector<Wire*>& wirevec);

	int getEventValue();
	int getEventTime();
	int getSortCount();
	friend bool operator<(const Event&r,const Event&l);

private:
	//name is name of wire that's changing
	string name;
	int time;
	int value;
	int sortcount;

};
#endif
