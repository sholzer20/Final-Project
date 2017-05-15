#include "Nurse.h"

void Nurse::setTreatmentTime()
{
	// Set a random treatment time from 1 to 10 minutes.
	treatmentTime = (rand() % 10) + 1;
}

void Nurse::newTreatment(Person * patient, int time)
{
	newPatient(patient);
	setTreatmentTime();
	setStartingTime(time);
}
