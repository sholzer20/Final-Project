#include "Simulator.h"
#include "readint.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

Simulator::Simulator(string fileName)
{

	// Have user set parameters.
	init();

	// Load in people.
	loadPeople(fileName);

	cout << town.size();	

	// Initialize RNG
	srand((unsigned int)std::time(0));

}

void Simulator::runSimulator(int hours)
{
	
	// Run the simulation for the pre-determined number of hours.
	for (currentTime = 0; currentTime < hours * 60; currentTime++) {

		cout << "Clock tick: " << currentTime << endl;

		// Check to see if a new illness has arisen, assuming there are any healthy people left.
		if ((double)rand() / (double)RAND_MAX < illnessRate && hospital->numberOfPatients() < town.size()) {

			// Find a healthy person to make sick, and pass them to the hospital.
			hospital->assignSeverity(newSick());

		}

		// Have the hospital update.
		hospital->update(currentTime);

	}
		

}

void Simulator::menu()
{

	// Display general results.
	cout << "Simulation complete." << endl;
	cout << "Total patient's treated: " << hospital->getTotalServed() << " patients." << endl;
	cout << "Average visit time: " << std::fixed << std::setprecision(2) << (double)hospital->getTotalTime() / (double)hospital->getTotalServed() << " minutes." << endl;
	cout << "Untreated patients at end of simulation: " << hospital->numberOfPatients() << " patients." << endl << endl;

	// Loop until the user chooses to end the program.
	while (true) {

		// Print out the menu.
		
		cout << "What would you like to view?" << endl << endl;
		cout << "1. List all treated patients" << endl;
		cout << "2. Look up patient records by name" << endl;
		cout << "3. Exit the simulation " << endl;
		int choice = read_int("", 1, 3);

		// Act according to the user's choice.
		if (choice == 1)
			hospital->displayTreatedPatients();
		else if (choice == 2) {
			string name;
			cout << "What patient would you like to look up records for?" << endl;
			cin.ignore();
			getline(cin, name);
			hospital->displayPatientRecord(name);
		}
		else break;

	}

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

	// Create an input stream.
	ifstream input;
	input.open(fileName.c_str());

	cout << "Loading people..." << endl << endl;

	int numberOfPeople = 0;

	// Check to make sure everything is ok!
	if (input.fail())
		cout << "ERROR:  TEXT FILE NOT FOUND. :(" << endl;
	else {

		string name;
		// Create people from the text file.
		while (getline(input, name)) {
			town.push_back(new Person(name));
			numberOfPeople++;
		}

	}

	cout << "Finished loading people." << endl;
	cout << numberOfPeople << " people found." << endl;

	// Close the input stream.
	input.close();

}

void Simulator::init()
{

	// Ask the user for information about the simulator.
	cout << "What is the illness rate in people/hour? (Max 60)" << endl;
	illnessRate = (double)read_int("", 1, 60) / 60.0;
	cout << "How many doctors are available to service patients? (max 20)" << endl;
	int doctors = read_int("", 1, 20);
	cout << "How many nurses are available to service patients? (max 10)" << endl;
	int nurses = read_int("", 1, 10);

	// Create the hospital with the given values.
	hospital = new Hospital(doctors, nurses);

}

Person * Simulator::newSick()
{

	// Randomly select citizens until a healthy one is found to make sick and pass back.
	while (true) {

		int randomPerson = rand() % town.size();
		if (!(town[randomPerson]->getSickness())) {
			town[randomPerson]->setSickness(true);
			town[randomPerson]->setAdmitTime(currentTime);
			cout << town[randomPerson]->getName() << " has become ill..." << endl;
			return town[randomPerson];
			break;
		}

	}

}
