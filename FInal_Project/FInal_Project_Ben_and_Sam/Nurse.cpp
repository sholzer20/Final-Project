#include "Nurse.h"

void Nurse::setTreatmentTime()
{
	// TODO set a random time between 1-10
}

void Nurse::newTreatment(Person * patient, int time)
{
	newPatient(patient);
	setTreatmentTime();
	setStartingTime(time);
}
