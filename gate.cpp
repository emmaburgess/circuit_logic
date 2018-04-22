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

int Gate::getOut() {
	return 0;
}
int Gate::getDelay() {
	return 0;
}
string Gate::getType() {
	return "";
}
bool Gate::gateOutput() {
	return 0;
}
