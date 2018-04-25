#ifndef GATE_HEADER
#define GATE_HEADER
#include <iostream>
#include <string>
#include "wire.h"
#include <vector>
using namespace std;

class Gate {
public:
	Gate();
	//Gate(string reftype, Wire* refin1, Wire* refin2, Wire* refout);
	Gate(string reftype, int refin1, int refin2, int refout);

	void setType(string ref);
	void setDelay(string ref);
	void setIn1(int ref);
	void setIn2(int ref);
	void setOut(int ref);

	Wire* getOut();
	int getDelay();
	string getType();

	int getIn1val();
	int getIn2val();
	int gateOutput();

private:
	string type;
	int delay;
	
	Wire* in1;
	Wire* in2;
	Wire* out;


};

#endif

