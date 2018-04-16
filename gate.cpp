//string k; n;
//int i;
//cin should be file stream
//cin >> k >> n >> i;

//#include fstream

#include <iostream>
#include "gate.h"
using namespace std;

Gate::Gate(string ref, int i1, int i2, int output) {
	type = ref;
	in1 = i1;
	in2 = i2;
	out = output;
}

void Gate::setType(string ref) {
	type = ref;
}
void Gate::setDelay(int ref) {

}
void Gate::setIn1(int ref) {

}
void Gate::setIn2(int ref) {

}
void Gate::setOut(int ref) {

}

int Gate::getOut() {

}
int Gate::getDelay() {

}
string Gate::getType() {

}
bool Gate::gateOutput() {

}