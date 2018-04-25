#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include"event.h"
#include"gate.h"
#include"wire.h"

using namespace std;

int main() {
	
	//Priority Queue
	priority_queue<Event>pqueue;
	

	// Make all the gates
		// Take info from Marshall's gate vector and use the constructor to make gates
	// Make all the wires to conect those gates
		// Somehow decide on how many wires you need (using the circuit definition)

	
	

	// Begin using the queue
		// Using pop_back

	for (int i = 0; i < 0/*length of the event vector*/; i++) {
		
			Event eventInUse;
			// Take the first event and do it

			// Pop the top Event e concerning Wire w1 from the Queue
			eventInUse = pqueue.top();
			pqueue.pop();

			// Find which wire
			string wname = eventInUse.getEventName();
			use the wire vector to find Wire (wname) wInUse;
			Wire wInUse;

			// Find which gate
			vector<Gate*> drivenGates = wInUse.getDrivers; //There will be problems with the getDrivers function (think deep copy type stuff). 

			// Determine if e causes a Gate g to change output Wire w2’s value. Going to have to try all the driven gates
			for (int j=0; j<sizeof(drivenGates);j++){
					
				Gate currentGate = *(drivenGates.at(j));

					int origOut = currentGate.gateOutput;
					int newOut = -1;
					if (currentGate.getType() == "NOT") {
						if (currentGate.getIn1val() == 0) {
							newOut = 1;
						}
						else if (currentGate.getIn1val() == 1) {
							newOut = 0;
						}
						else {
							newOut = -1;
						}
					}
					else if (currentGate.getType() == "AND") {
						if (currentGate.getIn1val() == 1) {
							if (currentGate.getIn2val() == 1) {
								newOut = 1;
							}
							else {
								newOut = 0;
							}
						}
						else {
							newOut = 0;
						}
					}
					else if (currentGate.getType() == "OR") {
						if (currentGate.getIn1val() == 1) {
							newOut = 1;
						}
						else if (currentGate.getIn2val() == 1) {
							newOut = 1;
						}
						else {
							newOut = 0;
						}
					}
					else if (currentGate.getType() == "NAND") {
						if ((currentGate.getIn1val() == 1) && (currentGate.getIn2val() == 1)) {
							newOut = 0;
						}
						else {
							newOut = 1;
						}
					}
					else if (currentGate.getType() == "NOR") {
						if ((currentGate.getIn1val() == 0) && (currentGate.getIn2val() == 0)) {
							newOut = 1;
						}
						else {
							newOut = 0;
						}
					}
					else if (currentGate.getType() == "XNOR") {
						if (currentGate.getIn1val() == currentGate.getIn2val()) {
							newOut = 1;
						}
						else if (currentGate.getIn1val() == -1 || currentGate.getIn2val() == -1) {
							newOut = -1;
						}
						else {
							newOut = 0;
						}
					}
					else if (currentGate.getType() == "XOR") {
						if (currentGate.getIn1val() == 1) {
							if (currentGate.getIn2val() == 0) {
								newOut = 1;
							}
							else if (currentGate.getIn2val() == 1) {
								newOut = 0;
							}
							else {
								newOut = -1;
							}
						}
						else if (currentGate.getIn1val() == 0) {
							if (currentGate.getIn2val() == 1) {
								newOut = 1;
							}
							else if (currentGate.getIn2val() == 0) {
								newOut = 0;
							}
							else {
								newOut = -1;
							}
						}
						else {
							newOut = -1;
						}

				}

				// If g’s output w2 will change, then schedule a future Event for w2
				if (newOut != origOut) {
					// we have to make a new event to make that change
					int sortcount;
					/*for (int k = 0; k < pqueue.size()-1; k++) {
						if (pqueue.at(k)->getEventTime() == eventInUse.getEventTime() + currentGate.getDelay()) {
							if (pqueue.at(k + 1)->getEventTime() > pqueue.at(k)->getEventTime())
								sortcount = pqueue.at(k)->getSortCount() + 1;
						}
					}*/
					
					Event newEvent = Event((currentGate.getOut())->getWireName, eventInUse.getEventTime() + currentGate.getDelay(), 
											newOut, sortcount);

					pqueue.push(newEvent);

					// make a new event using the constructor, making it at time T of this previous event + gate delay, 
					// with the wire that is the output for this gate
				}
				// Apply the effects of e to w1
				wInUse.setWireValue = newOut;
				// Put this event in wire history Might have to deal with empty history vector situation
				for (int k = 0; k < eventInUse.getEventTime; k++) {
					if (wInUse.getHistory(k) != 1 && wInUse.getHistory(k) != 0 && wInUse.getHistory(k) != -1) {
						wInUse.insertHistory(newOut, k);
					}
					
				}
				
			}

				
	}

	// Print the graphs

	for (all the wires) {
		cout << "Wire " << w.name << ": " << endl;
		for (int i = 0; i < sizeof(w.history); i++) {
			if (w.history.at(i) == 1) {
				cout << "-";
			}
			else if (w.history.at(i) == 0) {
				cout << "_";
			}
			else if (w.history.at(i) == -1) {
				cout << "x";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
		for (int i = 0; i < sizeof(w.history); i++) {
			if (i % 5 == 0) {
				cout << 0;
			}
			else if (i % 5 == 5) {
				cout << 5;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
return 0;
}