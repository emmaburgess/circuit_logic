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
	in1 = NULL;
	in2 = NULL;
	out = NULL;
}

/*Gate::Gate(string reftype, Wire* refin1, Wire* refin2, Wire* refout) {
	type = reftype;
	in1 = refin1;
	in2 = refin2;
	out = refout;
}*/


void Gate::setType(string ref) {
	type = ref;
}
void Gate::setDelay(string ref) {
	string temp = ref;
	temp.erase(temp.length() - 2, temp.length());
	delay = atoi(temp.c_str());
}
void Gate::setIn1(Wire* ref) {
	in1 = ref;
}
void Gate::setIn2(Wire* ref) {
	in2 = ref;
}
void Gate::setOut(Wire* ref) {
	out = ref;
}

int Gate::getOut() {
	return 0;
}
int Gate::getDelay() {
	return 0;
}
string Gate::getType() {
	return "";
}
int Gate::gateOutput() {
	return 0;
}