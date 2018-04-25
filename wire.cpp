#include "wire.h"
#include "gate.h"
using namespace std;

Wire::Wire(){
	value = -1;
	name = "";
	index = 0;
	used = "EMPTY";
}

//Wire::Wire(string val, string nm, int index, vector<Gate*> &connections){}

void Wire::setWireValue(int ref)
{
	value = ref;
}

void Wire::setWireName(string nameref)
{
	name = nameref;
}

void Wire::setIndex(int ref)
{
	index = ref;
}

void Wire::setUsedAs(string ref)
{
	used = ref;
}

//void Wire::setDrivers(vector<Gate*> ref){}

void Wire::addDriver(Gate* gateref)
{
	drivers.push_back(gateref);
}

string Wire::getUsed()
{
	return used;
}

int Wire::getWireValue()
{
	return value;
}

string Wire::getWireName()
{
	return name;
}

int Wire::getIndex()
{
	return index;
}
