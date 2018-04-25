
//PUT EX. WIRES IN VECTOR IN PROPER SLOT. IF WIRE 100 PUT IT IN VECTOR SPOT 100
//CHANGE GATE INPUTS TO WIRE POINTERS POINTING TO THE WIRES
//

//write fct that returns pointer to wire that event is changing

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "wire.h"
#include "gate.h"
#include "event.h"
#include <queue>

using namespace std;

void parsedescription(string &filename, string &circname, string &timedelay, vector<Gate*> &gateref, vector<Wire*> &wireref);
void parseevents(string &vecfilename, priority_queue<Event>&pqevents, vector<Wire*>&vecwire);


int main(){
	
	string filename;
	
	string circname;
	string wirename;
	string timedelay;
	
	vector<Gate*> gatevector;

	priority_queue<Event>events;

	vector<Wire*> wirevector;

	//DESCRIPTION
	parsedescription(filename, circname, timedelay, gatevector, wirevector);
	
	string vecfilename = filename;

	//VECTOR
	parseevents(vecfilename, events, wirevector);
	return 0;
}

void parseevents(string &vecfilename, priority_queue<Event>&pqevents, vector<Wire*>&wirevec) {

	bool parsingvec = true;
	string current;
	int vecloc = 0;
	string wire;
	int time;
	int val;


	vecfilename.erase(vecfilename.length() - 4, vecfilename.length());
	vecfilename = vecfilename + "_v.txt";

	ifstream vecread;
	vecread.open(vecfilename.c_str());

	while (parsingvec) {

		if (!vecread.is_open()) {
			cout << "No vector file found" << endl;
			continue;
		}
		while (!vecread.eof()) {
			
			vecread >> current;
			//Vecfile name
			if (current == "VECTOR") {
				vecread >> vecfilename;
			}
			//Input changes
			else{
				Event tempevent;

				vecread >> wire;
				tempevent.setEventName(wire);
				vecread >> time;
				tempevent.setTime(time);
				vecread >> val;
				tempevent.setEventValue(val);

				Wire* temp = tempevent.getWirePTR(wirevec);
				tempevent.setSortCount(temp->getIndex());
				pqevents.push(tempevent);
			}
		}
		parsingvec = false;
	}
}


void parsedescription(string &filename, string &circname, string &timedelay, vector<Gate*> &gateref, vector<Wire*> &wireref) {

	int inp1;
	int inp2;
	int outp;

	string gatename;
	bool keeprunning = true;
	string current;
	string wirename;
	int wirenum = 0;
	int gatenum = 0;
	
	while (keeprunning) {

		cout << "File name: ";
		cin >> filename;
		cout << endl;
		ifstream read;
		read.open(filename.c_str());

		if (!read.is_open()) {
			cout << "File not opened" << endl;
			continue;
		}

		while (!read.eof()) {
			read >> current;

			//Circuit
			if (current == "CIRCUIT") {
				read >> circname;
			}

			//Input/Output
			else if (current == "INPUT" || current == "OUTPUT") {
				read >> wirename;
				read >> wirenum;
				wireref.push_back(new Wire());

				if (wireref.size() <= wirenum+1) {
					for (int i = wirenum - wireref.size() + 1; i <= wirenum; i++) {
						wireref.push_back(new Wire());
					}
				}
				wireref.at(wirenum)->setWireName(wirename);
				wireref.at(wirenum)->setIndex(wirenum);

				if (current == "INPUT") {
					wireref.at(wirenum)->setUsedAs("INPUT");
				}
				else {
					wireref.at(wirenum)->setUsedAs("OUTPUT");
				}
			}

			//Gate
			else {

				gateref.push_back(new Gate());
				gateref.at(gatenum)->setType(current);
				read >> timedelay;
				gateref.at(gatenum)->setDelay(timedelay);

				//Wire pointer to set a gate input/output to
				Wire* temp = NULL;

				//Takes in the first input to the gate
				read >> inp1;
				
				//Is the wire created yet?

				//Not created yet
				if (wireref.at(inp1)->getUsed() == "EMPTY") {

					//potential issue if inp1 is out of range of vector
					wireref.at(inp1)->setUsedAs("INNERWIRE");
					wireref.at(inp1)->setIndex(inp1);
					wireref.at(inp1)->addDriver(gateref.at(gatenum));
					wireref.at(inp1)->setWireName(to_string(inp1));
				}

				//Already created ex. Wire A would have been created above
				else {
					wireref.at(inp1)->addDriver(gateref.at(gatenum));
				}
				
				//use the temp wire pointer 
				temp = wireref.at(inp1);
				gateref.at(gatenum)->setIn1(temp);



				//Input 2 is not necessary for NOT gate
				if (gatename != "NOT") {
					read >> inp2;
					if (wireref.at(inp2)->getUsed() == "EMPTY") {

						//potential issue if inp1 is out of range of vector
						wireref.at(inp2)->setUsedAs("INNERWIRE");
						wireref.at(inp2)->setIndex(inp2);
						wireref.at(inp2)->addDriver(gateref.at(gatenum));
						wireref.at(inp2)->setWireName(to_string(inp2));
					}
					else {
						wireref.at(inp2)->addDriver(gateref.at(gatenum));
					}
					temp = wireref.at(inp2);
					gateref.at(gatenum)->setIn2(temp);
				}

				read >> outp;
				//Don't need the output wire pointing to the gate
				//But do need to make sure the wire has been created
				if (wireref.at(outp)->getUsed() == "EMPTY") {

					//potential issue if inp1 is out of range of vector
					wireref.at(outp)->setUsedAs("INNERWIRE");
					wireref.at(outp)->setIndex(outp);
					wireref.at(outp)->addDriver(gateref.at(gatenum));
					wireref.at(outp)->setWireName(to_string(outp));
				}

				temp = wireref.at(outp);
				gateref.at(gatenum)->setOut(temp);
			
			
			gatenum++;
			}
		}
		keeprunning = false;
	}
}