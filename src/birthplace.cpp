/*
 * birthplace.cpp
 *
 *  Created on: 21 mar. 2018
 *      Author: usuario
 */

#include "birthplace.h"


BirthPlace::BirthPlace (string place, string province, int number){
	this->place = place;
	this->number = number;
	this ->province = province;
}

void BirthPlace::show () {
	cout << this->place << " -> " << this->province << " -> " << this->number << endl;
}

