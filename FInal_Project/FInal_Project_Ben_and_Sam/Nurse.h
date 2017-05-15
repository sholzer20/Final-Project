#ifndef NURSE_H_
#define NURSE_H_
#include "HospitalStaff.h"

class Nurse : public HospitalStaff {

public:
	virtual void setTreatmentTime();
	virtual void newTreatment(Person* patient, int time);
};
#endif