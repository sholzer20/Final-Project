#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {

private:
	bool isSick;
	int admitTime;
	int severity;
	std::string name;


public:
	Person(std::string name);

	int getSeverity();
	int getAdmitTime() { return admitTime; }
	std::string getName() { return name; }
	bool getSickness();

	void setAdmitTime(int time) { admitTime = time; }
	void setSeverity(int severity);
	void setSickness(bool sick);
	
	
};


#endif