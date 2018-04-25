#include "event.h"

Event::Event(string nameref, int timeref, int valref, int sortcountref)
{
	name = nameref;
	time = timeref;
	value = valref;
	sortcount = sortcountref;
}

Event::Event()
{
	name = "";
	time = -2;
	value = -2;
	sortcount = 0;
}

void Event::setEventName(string ref)
{
	name = ref;
}

void Event::setTime(int ref)
{
	time = ref;
}

void Event::setEventValue(int ref)
{
	value = ref;
}

void Event::setSortCount(int ref)
{
	sortcount = ref;
}

Wire * Event::getWirePTR(vector<Wire*>& wirevec)
{
	for (int i = 0; i <= wirevec.size(); i++) {
		if (name == wirevec.at(i)->getWireName()) {
			Wire* temp = wirevec.at(i);
			return temp;
		}
	}
	cout << "Couldn't find wire" << endl;
	return nullptr;
	return nullptr;
}


int Event::getEventValue()
{
	return 0;
}

int Event::getEventTime()
{
	return 0;
}

int Event::getSortCount()
{
	return 0;
}

bool operator<(const Event & r, const Event & l)
{
	if (r.time == l.time) {
		return r.sortcount > l.sortcount;
	}
	return r.time > l.time;
}
