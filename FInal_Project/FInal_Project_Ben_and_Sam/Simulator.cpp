#include "Simulator.h"
#include "readint.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Simulator::Simulator(string fileName)
{

	// Have user set parameters.
	init();

	// Load in people.
	loadPeople(fileName);

	// Initialize RNG
	srand((unsigned int)std::time(0));

}

void Simulator::runSimulator(int hours)
{
	
	// Run the simulation for the pre-determined number of hours.
	for (currentTime = 0; currentTime < hours * 60; currentTime++) {

		// Check to see if a new illness has arisen, assuming there are any healthy people left.
		if (rand() / RAND_MAX < illnessRate && hospital->numberOfPatients < town.size()) {

			// Find a healthy person to make sick, and pass them to the hospital.
			hospital->assignSeverity(newSick());

		}

		// Have the hospital update.
		hospital->update();

	}
		

}

void Simulator::menu()
{
}

Simulator::~Simulator()
{
	
	// Delete stuff.
	delete hospital;
	for (int i = 0; i < town.size(); i++)
		delete town[i];

}

void Simulator::loadPeople(string fileName)
{
}

void Simulator::init()
{

	// Ask the user for information about the simulator.
	cout << "What is the illness rate in people/hour? (Max 60)" << endl;
	illnessRate = read_int("", 1, 60);
	cout << "How many doctors are available to service patients?" << endl;
	int doctors = read_int("", 1, 20);
	cout << "How many nurses are available to service patients?" << endl;
	int nurses = read_int("", 1, 20);

	// Create the hospital with the given values.
	hospital = new Hospital(doctors, nurses);

}

Person * Simulator::newSick()
{

	// Randomly select citizens until a healthy one is found to make sick and pass back.
	while (true) {

		int randomPerson = rand() % town.size();
		if (!town[randomPerson]->isSick()) {
			town[randomPerson]->makeSick();
			return town[randomPerson];
			break;
		}

	}

}
