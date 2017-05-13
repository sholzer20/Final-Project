#include "Record.h"
#include <iostream>
using std::cout;
using std::endl;

Record::Record()
{
	visits = 0;
}

// Concatenates the patient's history from # of visits and the vector of severities
void Record::display()
{
	cout << "------------------- Patient's History -------------------"<< endl;
	cout << "Visits to the hospital: " << visits << endl;
	cout << "Severity upon each visit: ";
	// Grabs each severity value, adds comma for each until the last
	for (unsigned int i = 0; i < severities.size(); i++)
	{
		if (i != (severities.size() - 1))
			cout << severities[i] << ", ";
		else
			cout << severities[i] << endl;
	}

	cout << "----------------------------------------------------------" << endl;
}

void Record::updateFile(int severity)
{
	visits++;
	severities.push_back(severity);
}
