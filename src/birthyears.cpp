/*
 * birthyears.cpp
 *
 *  Created on: 16 mar. 2018
 *      Author: jarico
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "birthyears.h"
using namespace std;



// PRIVATE operations


// Separate fields with multiple items with the format:
//   year1 (number1) ; year2 (number2) ; year3 (number3)
void BirthYears::separateYears  (string birthyears) {

	const char DELIM = ';';
	std::string::size_type pos;
	std::string::size_type beg_index, end_index;

	beg_index = 0;
	while (beg_index != std::string::npos) {

		end_index = birthyears.find_first_of(DELIM, beg_index);
		if (end_index == std::string::npos)
			end_index = birthyears.length();

		string item = birthyears.substr(beg_index, end_index - beg_index);

		// Extract year and number of an item:  1945 (7)
		pos = item.find('(');
		item.erase(pos, 1);

		pos = item.find(')');
		item.erase(pos, 1);

		pos = item.find(' ');
		string y = item.substr(0, pos);
		string n = item.substr(pos, end_index - pos);

		BirthYear *by = new BirthYear (atoi(y.c_str()), atoi(n.c_str()));
		this->byears->enqueue(by);

		beg_index = birthyears.find_first_not_of(DELIM, end_index);
	}
}

// PUBLIC INTERFACE

BirthYears::BirthYears () {
	this->byears  = new Queue <BirthYear *>  ();
}


BirthYears::~BirthYears () {
	cout << "~ BirthYears" << endl;

	while ( ! this->byears->empty()) {
		BirthYear *by = this->byears->front();
		this->byears->dequeue();
		delete by;
	}
	delete this->byears;
}


void BirthYears::putBirthYears (string years) {
	this->separateYears  (years);
}


void BirthYears::show () {

	cout << "[BirthYear] show " << endl;
	cout << "---------------" << endl << endl;

	Queue<BirthYear *> *tmp = new Queue<BirthYear *> ();

	while ( ! this->byears->empty()) {
		BirthYear *by = this->byears->front();
		this->byears->dequeue();
		tmp->enqueue(by);

		by->show();
	}

	while ( ! tmp->empty()) {
		BirthYear *by = tmp->front();
		tmp->dequeue();
		this->byears->enqueue(by);
	}

	delete tmp;
}
