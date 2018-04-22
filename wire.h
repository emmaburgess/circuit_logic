#ifndef WIRE_HEADER
#define WIRE_HEADER
#include<string>
#include<iostream>
#include<vector>
#include "gate.h"
#include "event.h"
using namespace std;

class Wire {
public:
	Wire();
	//Wire(string val, string nm, int index, vector<Gate*> &connections);

	void setWireValue(string ref);
	void setWireName(string name);
	void setIndex(int ref);
	void setInput(bool ref);
	//void setDrivers(vector<Gate*>ref);

	string getWireValue();
	string getWireName();
	int getIndex();


private:
	string value;
	string name;
	int index;
	bool input;
	//vector<Gate*> drivers[10];
	//Where will you keep the history?
};
#endif
