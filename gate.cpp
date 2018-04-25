//string k; n;
//int i;
//cin should be file stream
//cin >> k >> n >> i;

//#include fstream

#include <iostream>
#include "gate.h"
#include "wire.h"
using namespace std;

Gate::Gate(){
	type = "";
	delay = 0;
	in1 = 0;
	in2 = 0;
	out = 0;
}

/*Gate::Gate(string reftype, Wire* refin1, Wire* refin2, Wire* refout) {
	type = reftype;
	in1 = refin1;
	in2 = refin2;
	out = refout;
}*/

Gate::Gate(string reftype, int refin1, int refin2, int refout) {

}

void Gate::setType(string ref) {
	type = ref;
}
void Gate::setDelay(string ref) {
	string temp = ref;
	temp.erase(temp.length() - 2, temp.length());
	delay = atoi(temp.c_str());
}
void Gate::setIn1(int ref) {
	in1 = ref;
}
void Gate::setIn2(int ref) {
	in2 = ref;
}
void Gate::setOut(int ref) {
	out = ref;
}

Wire* Gate::getOut() {
	return out;
}
int Gate::getDelay() {
	return delay;
}
string Gate::getType() {
	return type;
}
int Gate::gateOutput() {
	return out->getWireValue;
}

int Gate::getIn1val() {
	return in1->getWireValue;
}
int Gate::getIn2val() {
	return in2->getWireValue;
}
