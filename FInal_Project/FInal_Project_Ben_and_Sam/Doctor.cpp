#include "Doctor.h"

void Doctor::setTreatmentTime()
{
	// TODO set a new random time between 1-20
}

void Doctor::newTreatment(Person * patient, int time)
{
	newPatient(patient);
	setTreatmentTime();
	setStartingTime(time);
}
