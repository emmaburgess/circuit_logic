#include <iostream>
using namespace std;

class Gate {
public: 
	Gate(string type, int in1, int in2, int out);

	void setType(string ref);
	void setDelay(int ref);
	void setIn1(int ref);
	void setIn2(int ref);
	void setOut(int ref);

	int getOut();
	int getDelay();
	string getType();

	bool gateOutput();

private:
	string type;
	int delay;
	int in1;
	int in2;
	int out;

};


