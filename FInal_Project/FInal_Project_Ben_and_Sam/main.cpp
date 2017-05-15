#include "Simulator.h"

// The main function which activates the simulator
int main() {

	Simulator* simulator = new Simulator("residents_of_273ville.txt");

	simulator->runSimulator(168);
	simulator->menu();

	delete simulator;

	// End program.  Everything is ok.
	return 0;

}