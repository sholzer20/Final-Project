#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "HospitalStaff.h"
#include "Person.h"
#include "Record.h"
#include <vector>
#include <queue>
#include <string>
#include <map>
using std::vector;
using std::string;

class Hospital {

private:
	int totalTime;
	int totalServed;
	vector<HospitalStaff*> hospitalStaff;
	vector<string> patientRoster;
	std::map<string, Record*> patientRecords;

public:
	Hospital();
	void assignSeverity(Person* patient);
	void updateRecord(Person* patient);
};

#endif