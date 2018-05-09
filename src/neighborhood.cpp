/*
 * neighborhood.cpp
 *
 *  Created on: 27 feb. 2018
 *      Author: jarico
 */

#include "neighborhood.h"


Neighborhood::Neighborhood () {
	this->count = 0;
}

Neighborhood::~Neighborhood () {

	cout << "[Neighborhood] Destructor." << endl;

	for (int i = 0; i < this->count; i++) {
		delete streets[i];
	}
	this->count = 0;
}


void Neighborhood::putName (string name) {
	this->name = name;
}

void Neighborhood::putDistrict (string district) {
	this->district = district;
}

string Neighborhood::getName () {
	return this->name;
}

void Neighborhood::getDistrict (string &district) {
	district = this->district;
}

void Neighborhood::show () {
	cout << "Neighborhood: " << this->name << " in district: " << this->district << endl;
}


void  Neighborhood::addVia (Via* v) {
	this->streets[this->count] = v;
	this->count++;
}

void  Neighborhood::showVias () {
	for (int i = 0; i < this->count; i++) {
		(this->streets[i])->show();
	}
}

void  Neighborhood::getLongestVia (Via* &v) {

	float longest = 0.0;
	for (int i = 0; i < this->count; i++) {
		if (this->streets[i]->getLength() > longest) {
			v = this->streets[i];
			longest = v->getLength();
		}
	}
}

void  Neighborhood::getVia (string name, Via* &v) {

	// TBD: removing all but one of the following versions

	// 1st version (quite inefficient)
	for (int i = 0; i < this->count; i++) {
		if (this->streets[i]->getName() == name) {
			v = this->streets[i];
		}
	}


	// 2nd version
	for (int i = 0; i < this->count; i++) {
		if (this->streets[i]->getName() == name) {
			v = this->streets[i];
			break;
		}
	}


	// 3rd version
	bool found = false;
	for (int i = 0; i < this->count && !found; i++) {
		if (this->streets[i]->getName() == name) {
			v = this->streets[i];
			found = true;
		}
	}


	// 4th version (you can also use break)
	int i = 0;
	found = false;
	while (!found && i < this->count) {
		if (this->streets[i]->getName() == name) {
			v = this->streets[i];
			found = true;
		}
	}

}


