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
	from that range to the patient object
	@param the patient pointer that has just gotten "sick 
*/
void Hospital::assignSeverity(Person * patient)
{
}

void Hospital::updateRecord(Person * patient)
{
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
