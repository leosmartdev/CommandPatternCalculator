// CommandPatternCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

#include "Client.h"

using std::cout;
using std::endl;

// main
int main(int argc, char * argv[]) {

	// cout << "Hello, I am starting successfully." << endl;

	// run main menu
	Client calculator;
	calculator.run();

	//cout << "\nHello, I am ending successfully." << endl;
}
