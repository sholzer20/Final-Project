#ifndef READINT_H
#define READINT_H

#include <string>

using std::string;

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
int read_int(const string &prompt, int low, int high);

#endif