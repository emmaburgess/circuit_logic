#include "event.h"

int Event::sortcount = 0;

Event::Event(string nameref, int timeref, int valref, int sortcountref)
{
	name = nameref;
	time = timeref;
	value = valref;
	sortcount++;
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
}

void Event::setSortCount(int ref)
{
	sortcount = ref;
}

int Event::getEventValue()
{
	return 0;
}

int Event::getEventTime()
{
	return time;
}

int Event::getSortCount()
{
	return 0;
}

string Event::getEventName() {
	return name;
}
