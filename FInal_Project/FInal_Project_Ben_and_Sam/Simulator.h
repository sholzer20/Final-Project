#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Person.h"
#include "Hospital.h"
using std::srand;
using std::rand;
using std::vector;
using std::string;


class Simulator {

public:

	// Creates a simulator which reads in "people" from the given text file.
	Simulator(string fileName);

	// Runs the simulator for the given number of hours.
	void runSimulator(int hours);

	// Displays the menu for viewing the latest results.
	void menu();

	// Deletes any objects that have been allocated to the heap.
	~Simulator();

private:

	vector<Person*> town; // The vector of people in the town.
	Hospital* hospital; // The hospital in the town.
	double illnessRate; // The rate (in people/minute) of illness.
	int currentTime; // The current time in minutes.

	// Load in people from the given text file
	void loadPeople(string fileName);

	// Initializes values for the simulator as decided upon by the user.
	void init();

	// Finds a health person to make sick.
	Person* newSick();

};


#endif