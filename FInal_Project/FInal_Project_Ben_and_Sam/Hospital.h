#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "HospitalStaff.h"
#include "Person.h"
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
	int totalTime;
	int totalServed;
	vector<HospitalStaff*> hospitalStaff;
	vector<string> patientRoster;
	std::map<string, Record*> patientRecords;

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