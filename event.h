#include<string>
#include<iostream>
using namespace std;

class Event {
public:
	Event(string name, int time, int val, int sortcount);

	//Crossed out
	/*void setEventName(string ref);
	void setTime(int ref);
	void setEventValue(int ref);
	void setSortCount(int ref);*/

	int getEventValue();
	int getEventTime();
	int getSortCount();

private:
	string name;
	int time;
	int value;
	int sortcount;

};
