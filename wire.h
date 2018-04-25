#ifndef WIRE_HEADER
#define WIRE_HEADER
#include<string>
#include<iostream>
#include<vector>
#include "gate.h"
#include "event.h"
using namespace std;


class Gate;
class Wire {
public:
	Wire();
	//Wire(string val, string nm, int index, vector<Gate*> &connections);

	void setWireValue(int ref);
	void setWireName(string name);
	void setIndex(int ref);
	void setUsedAs(string ref);
	
	
	void addDriver(Gate* ref);

	string getUsed();
	int getWireValue();
	string getWireName();
	int getIndex();


private:

	//0,1,-1
	int value;

	//A,B,C ex.  How to distinguish input and output wires from each other
	//See string used below for more info on the wire
	string name;
	
	//Wire number location in vector
	int index;

	//Is this wire in the vector being used or just a placeholder for the vector
	//"EMPTY" = placeholder
	//"INNERWIRE" It's used in the system but is not an input or output
	//"OUTPUT" and "INPUT" self explanatory
	string used;

	//Which gates is this wire pointing to
	vector<Gate*> drivers;
	//Where will you keep the history?
};
#endif