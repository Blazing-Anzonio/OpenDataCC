/*
 * via.cpp
 *
 *  Created on: 7 mar. 2018
 *      Author: jarico
 */

#include "via.h"

#include <iostream>
using namespace std;


Via::Via () {

	this->code    = 0;
	this->length  = 0.0;
	this->males   = 0;
	this->females = 0;
	this->birthYears = new BirthYears ();
	this->birthPlaces = new BirthPlaces ();
	this->eduInfo = new EducationInfo ();
	this->natioInfo = new NationalityInfo();
	this->year = 0;
}

Via::~Via () {
	delete this->birthYears;
}


void Via::putCode (int code) {
	this->code = code;
}

void Via::putName (string name) {
	this->name = name;
}

void Via::putLength (float length) {
	this->length = length;
}

void Via::putMale(int male){
	this->males = male;
}

void Via::putFemale(int female){
	this->females = female;
}

void Via::putYear(int year){
	this->year = year;
}
string Via::getName () {
	return this->name;
}

float Via::getLength () {
	return this->length;
}

void Via::putNeigh(string neigh){
	this->neigh = neigh;
}

void Via::putType(string type){
	this->type = type;
}


void Via::putBirthYears (string byears) {
	this->birthYears->putBirthYears  (byears);
}

void Via::putBirthplaces(string place) {
	this->birthPlaces->putBirthPlaces(place);
}

void Via::putEducationInfo(string level) {
	this->eduInfo->putEducation(level);
}

void Via::putNationalityInfo(string country) {
	this->natioInfo->putNationalityInfo(country);
}

void Via::show () {
	cout << type << " " << name << " with code " << code << " and length " << length << " is in neighborhood " << neigh << endl;
	this->birthYears->show();
}

