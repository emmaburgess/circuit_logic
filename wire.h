#include<string>
#include<iostream>
#include<vector>
#include "gate.h"
using namespace std;

class Wire {
public:
	Wire(string val, string nm, int index, vector<Gate*> connections);

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

};
