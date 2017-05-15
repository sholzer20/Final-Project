#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "HospitalStaff.h"
#include "Person.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Record.h"
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using std::vector;
using std::string;
using std::cout;

class Hospital {

private:
	// Will keep track of the total time patients were being treated
	int totalTime;
	// The total number of patients served by the hospital, including multiple visits by same patient
	int totalServed;

	// The Doctors and Nurses that will treat patients
	vector<HospitalStaff*> hospitalStaff;

	// A list of all the patients treated by the hospital
	vector<string> patientRoster;

	// Contains a record object for each patient by the name of the Person object
	std::map<string, Record*> patientRecords;

	// Only contains patients with the severities 11-20 (only Doctor can treat)
	std::priority_queue<Person*> highPriority;
	// Contains patients with severities 1-10 (can be treated by both Nurses and Doctors)
	std::priority_queue<Person*> lowPriority;

public:
	Hospital(int doctors, int nurses);

	void assignSeverity(Person* patient);
	void updateRecord(Person* patient);
	void displayTreatedPatients();
	void displayPatientRecord(string name);

	int getTotalTime() { return totalTime; }
	int getTotalServed() { return totalServed; }
	int numberOfPatients();
};

#endif