#include "Hospital.h"

Hospital::Hospital(int doctors, int nurses)
{
	// Adds the correct number of doctors and nurses into the hospitalStaff vector
	for (int i = 0; i < doctors; i++)
		hospitalStaff.push_back(new Doctor());
	for (int i = 0; i < nurses; i++)
		hospitalStaff.push_back(new Nurse());

	totalTime = 0;
	totalServed = 0;
}

/* Determines the range of the severity with one random value, then assigns a severity 
	from that range to the patient object. Adds the patient to the appropriate priority_queue
	@param the patient pointer that has just gotten "sick 
*/
void Hospital::assignSeverity(Person * patient)
{
	double random = ((double) rand() / RAND_MAX);
	int severity;
	// Severities between 1-10
	if (random <= .7) {
		severity = (rand() % 10) + 1;
		lowPriority.push(patient);
	}
	// Severitites between 11-15
	else if (random > .7 && random <= .9) {
		severity = (rand() % 5) + 11;
		highPriority.push(patient);
	}
	// Severities between 16-20
	else if (random > .9) {
		severity = (rand() % 5) + 16;
		highPriority.push(patient);
	}

	patient->setSeverity(severity);
}

// This function is called once the Doctor or Nurse has completely treated a patient
// Updates the patient's record to add a visit and their severity to the record
void Hospital::updateRecord(Person * patient)
{
	patientRecords[patient->getName()]->updateFile(patient->getSeverity());
}

/*	A function to display the names of all the patients treated by the hospital. 
	A person's name is added to the roster when they are treated by the hospital */
void Hospital::displayTreatedPatients()
{
	for (int i = 0; i < patientRoster.size(); i++)
	{
		if (i != (patientRoster.size() - 1))
			cout << patientRoster[i] << ", ";
		else
			cout << patientRoster[i] << std::endl;
	}
}

// Will acccess the correct patient record from the map based on the name of the patient
// Calls the display function on the record object
void Hospital::displayPatientRecord(string name)
{
	patientRecords[name]->display();
}

// Accessor for the number of Person objects held in the Hospital
// @ return The combined size of both the priority queues
int Hospital::numberOfPatients()
{
	return highPriority.size() + lowPriority.size();
}
