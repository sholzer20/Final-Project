#include "Person.h"

Person::Person(std::string name)
{
	this->name = name;
}

int Person::getSeverity()
{
	return severity;
}

void Person::setSeverity(int severity)
{
	this->severity = severity;
}

void Person::setSickness(bool sick)
{
	isSick = sick;
}

bool Person::getSickness()
{
	return isSick;
}
