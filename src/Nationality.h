/*
 * Nationality.h
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */

#ifndef Nationality_H_
#define Nationality_H_
#include <string>
#include <iostream>
using namespace std;

class Nationality {
private:

	string country;
	int number;

public:

	Nationality(string country, int number);

	void show();
};




#endif /* Nationality_H_ */
