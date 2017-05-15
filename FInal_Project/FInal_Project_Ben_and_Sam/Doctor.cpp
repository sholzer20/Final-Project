#include "Doctor.h"
#include <cstdlib>
using std::rand;

void Doctor::setTreatmentTime()
{
	// Set a random treatment time from 1 to 20 minutes.
	treatmentTime = (rand() % 20) + 1;
}

void Doctor::newTreatment(Person * patient, int time)
{
	newPatient(patient);
	setTreatmentTime();
	setStartingTime(time);
}
