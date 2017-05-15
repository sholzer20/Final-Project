#include "Hospital.h"

Hospital::Hospital(int doctors, int nurses)
{
}

void Hospital::assignSeverity(Person * patient)
{
}

void Hospital::updateRecord(Person * patient)
{
}

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

void Hospital::displayPatientRecord(string name)
{
	patientRecords[name]->display();
}
