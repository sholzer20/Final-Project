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

	// Create the record if it does not exist already, and add the patient to the roster.
	if (patientRecords.count(patient->getName()) == 0) {
		patientRecords[patient->getName()] = new Record();
		patientRoster.push_back(patient->getName());
	}

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
		if (i % 10 == 9)
			cout << std::endl;
	}
}

// Will acccess the correct patient record from the map based on the name of the patient
// If the patient has no records, the user is informed that no patient was found.
// Calls the display function on the record object
void Hospital::displayPatientRecord(string name)
{
	if (patientRecords.count(name) > 0) 
		patientRecords[name]->display();
	else cout << "No patient found with name " << name << "." << std::endl;

}


// Checks to see if new patients can be accepted, or if patients being treated are ready to be discharged.
void Hospital::update(int currentTime)
{

	// Check for patients ready to be discharged.
	for (int i = 0; i < hospitalStaff.size(); i++) {
		if (hospitalStaff[i]->getPatient() != NULL &&
			currentTime - hospitalStaff[i]->getStartingTime() == hospitalStaff[i]->getTreatmentTime()) {

			

			// Update hospital records.
			totalServed++;
			totalTime += currentTime - hospitalStaff[i]->getPatient()->getAdmitTime();
			updateRecord(hospitalStaff[i]->getPatient());

			// Make the patient well.
			hospitalStaff[i]->getPatient()->setSickness(false);

			// Release the patient from the doctor's care.
			hospitalStaff[i]->finishTreatment();

		}

	}

	// Check to see if doctor's are available to treat the severe priority queue
	for (int i = 0; i < hospitalStaff.size(); i++) {
		if (typeid(Doctor) == typeid(*(hospitalStaff[i]))
			&& hospitalStaff[i]->getPatient() == NULL
			&& highPriority.size() > 0) {

			// If all the conditions passed, set the doctor up with the new patient.
			hospitalStaff[i]->newTreatment(highPriority.top(), currentTime);
			highPriority.pop();

		}
	}

	// First, check nurses for treating the low priority queue since they are faster.
	for (int i = 0; i < hospitalStaff.size(); i++) {
		if (typeid(Nurse) == typeid(*(hospitalStaff[i]))
			&& hospitalStaff[i]->getPatient() == NULL
			&& lowPriority.size() > 0) {

			// If all the conditions passed, set the nurse up with the new patient.
			hospitalStaff[i]->newTreatment(lowPriority.top(), currentTime);
			lowPriority.pop();

		}
	}

	// If no nurses are available to treat remaining low priority patients, check for doctors.
	for (int i = 0; i < hospitalStaff.size(); i++) {
		if (typeid(Doctor) == typeid(*(hospitalStaff[i]))
			&& hospitalStaff[i]->getPatient() == NULL
			&& lowPriority.size() > 0) {

			// If all the conditions passed, set the doctor up with the new patient.
			hospitalStaff[i]->newTreatment(lowPriority.top(), currentTime);
			lowPriority.pop();

		}
	}

}

// Accessor for the number of Person objects held in the Hospital
// @ return The combined size of both the priority queues
int Hospital::numberOfPatients()
{

	// Keeps track of how many doctors and nurses are treating patients.
	int treating = 0;
	for (int i = 0; i < hospitalStaff.size(); i++)
		if (hospitalStaff[i]->getPatient() != NULL) treating++;

	return (highPriority.size() + lowPriority.size() + treating);
}
