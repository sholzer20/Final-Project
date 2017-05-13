#include <stdexcept>
#include <iostream>
#include <limits>
#include <ios>
#include <string>

///////////////////////
// Ben Morledge-Hampton
// 
// Partial to Parties
//
// 4/27/2017
///////////////////////

/**
Function to return an integer as it is input by the user.
However, the program will only return the integer if it
falls within the given bounds.  If a non-number is entered,
the function will discard the invalid input, and reprompt for input.
If a number outside of the range is given, the function will ask again
until valid input is obtained.  If the given range is empty, an
invalid_argument exception will be thrown.
@param prompt The message displayed to the user to prompt input.
@param low The lowest acceptable integer.
@param high The highest acceptable integer.
@Return the user's valid input.
*/
int read_int(const std::string &prompt, int low, int high) {

	// Throw an invalid_argument exception if the given range is empty.
	if (high - low < 1) throw std::invalid_argument("Range is empty");

	std::cin.exceptions(std::ios_base::failbit);
	int num = 0;
	while (true) { // Loop until valid input is received.

		try {
			// Read in the user's input.
			std::cout << prompt;
			std::cin >> num;
			// Check to see if the response falls within the bounds.
			// If it does, return it.
			if (num >= low && num <= high) return num;
			// If it doesn't, reprompt for input.
			else std::cout << "That is not within the given bounds.\n";
		}
		catch (std::ios_base::failure& ex) {
			std::cout << "Bad numeric string -- try again\n";
			// Reset the error flag
			std::cin.clear();
			// Skip current input line
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}

}