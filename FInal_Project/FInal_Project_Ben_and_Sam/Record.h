#ifndef RECORD_H
#define RECORD_H
#include <vector>
#include <string>

class Record {

private:
	int visits;
	std::vector<int> severities;

public:
	Record();
	void display();
	void updateFile(int severity);
};


#endif