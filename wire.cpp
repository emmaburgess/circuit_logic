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

string Wire::getWireValue()
{
	return string();
}

string Wire::getWireName()
{
	return string();
}

int Wire::getIndex()
{
	return 0;
}
