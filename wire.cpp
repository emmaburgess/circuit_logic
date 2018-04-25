#include "wire.h"
#include "gate.h"
using namespace std;

Wire::Wire(){
	value = "";
	name = "";
	index = 0;
	input = false;
}

//Wire::Wire(string val, string nm, int index, vector<Gate*> &connections){}

void Wire::setWireValue(string ref)
{
}

void Wire::setWireName(string name)
{
}

void Wire::setIndex(int ref)
{
}

void Wire::setInput(bool ref)
{
	input = ref;
}

//void Wire::setDrivers(vector<Gate*> ref){}

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
	return 0;
}

vector<Gate*> Wire::getDrivers() {
	return drivers;
}

void Wire::insertHistory(int valRef, int timeRef) {
	vector<int>::iterator it;
	it = history.begin();
	history.insert(it+1+timeRef, valRef);
}
int Wire::getHistory(int timeRef) {
	if (sizeof(history) < timeRef) {
		return -2;
	}
	return history.at(timeRef + 1);
}