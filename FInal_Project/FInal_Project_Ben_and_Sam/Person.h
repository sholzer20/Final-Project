#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {

private:
	int severity;
	bool isSick;
	std::string name;

public:
	Person(std::string name);

	int getSeverity();
	void setSeverity(int severity);
	void setSickness(bool sick);
	bool getSickness();
};


#endif