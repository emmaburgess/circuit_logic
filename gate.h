#ifndef GATE_HEADER
#define GATE_HEADER
#include <iostream>
#include <string>
#include "wire.h"
#include <vector>
using namespace std;

class Wire;
class Gate {
public:
	Gate();

	void setType(string ref);
	void setDelay(string ref);
	void setIn1(Wire* ref);
	void setIn2(Wire* ref);
	void setOut(Wire* ref);

	int getOut();
	int getDelay();
	string getType();

	int gateOutput();

private:
	string type;
	int delay;

	Wire* in1;
	Wire* in2;
	Wire* out;
};

#endif

