/*
 * Nationality.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */
#include "Nationality.h"
#include <iostream>
#include <string>

Nationality::Nationality(string country, int number) {
	this->country = country;
	this->number = number;
}

void Nationality::show() {
	cout << this->country << "-" << this->number << endl;
}
