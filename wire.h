#include<string>
#include<iostream>
#include<vector>
#include "gate.h"
using namespace std;

class Gate; //Needed a forward declaration
class Wire {
public:
	Wire(string val, string nm, int index, vector<Gate*> connections);

	//Crossed the next three out but also wrote 'keep' so I don't know 
	void setWireValue(string ref);
	void setWireName(string name);
	void setIndex(int ref);
	
	void setDrivers(vector<Gate*>ref);

	string getWireValue();
	string getWireName();
	int getIndex();
	

private:
	string value;
	string name;
	int index;
	vector<Gate*> drivers;
	//Where will you keep the history?
};
