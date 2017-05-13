#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "HospitalStaff.h"
#include "Person.h"

class Doctor : HospitalStaff {

public:
	virtual void setTreatmentTime();
	virtual void newTreatment(Person* patient, int time);
};

#endif