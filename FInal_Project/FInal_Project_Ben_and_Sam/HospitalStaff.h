#ifndef HOSPITALSTAFF_H_
#define HOSPITALSTAFF_H_
#include "Person.h"
class HospitalStaff {

private:
	// Will be null if they are available to treat a new Patient
	Person* patient;
	// How long they will take to treat the patient. Resets every time the staff gets a new patient
	int treatmentTime;
	// The time they started treating the newest patient
	int startingTime;
public:

	// Umbrella class to call the following three classes. Happens every time staff gets new patient
	virtual void newTreatment(Person* patient, int time) = 0;

	//Resets the Person pointer to a new patient
	void newPatient(Person* patient) { this->patient = patient; }
	// Treatment time controlled by the base class
	virtual void setTreatmentTime() = 0;
	// Starting time will be passed to the staff member by hospital/simulator
	void setStartingTime(int time) { startingTime = time; }

	// Getters for private member variables
	int getStartingTime() { return startingTime; }
	Person* getPatient() { return patient; }
	int getTreatmentTime() { return treatmentTime; }
	
};

#endif