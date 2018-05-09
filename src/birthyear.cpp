/*
 * birthyear.cpp
 *
 *  Created on: 16 mar. 2018
 *      Author: jarico
 */

#include "birthyear.h"

#include <iostream>
using namespace std;


BirthYear::BirthYear (int year, int number) {
	this->year   = year;
	this->number = number;
}

void BirthYear::show () {
	cout << this->year << " -> " << this->number << endl;
}
