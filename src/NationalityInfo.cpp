/*
 * NationalityInfo.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */
#include "NationalityInfo.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

void NationalityInfo::separateCountries(string country) {
	const char DELIM = ';';
	std::string::size_type beg_index, end_index;
	beg_index = 0;
	while (beg_index != std::string::npos) {
		end_index = country.find_first_of(DELIM, beg_index);

		if (end_index == std::string::npos)
			end_index = country.length();

		string item = country.substr(beg_index, end_index - beg_index);
		std::string::size_type start, end;

		start = 0;
		end = item.find_first_of('(', start);
		string i1 = item.substr(start, end - start);
		item.erase(start, end - start + 1);

		end = item.find_first_of(')', start);
		string i2 = item.substr(start, end - start);
		item.erase(start, end - start + 1);

		if (end != std::string::npos) {
			start = end + 1;
			end = item.find_first_of(')', start);
			string i2 = item.substr(start, end - start);

			Nationality *N = new Nationality (i1, atoi(i2.c_str()));
			N->show();

		} else {
			Nationality *N = new Nationality (i1, atoi(i2.c_str()));
			N->show();
		}


		beg_index = country.find_first_not_of(DELIM, end_index);
	}
}

NationalityInfo::NationalityInfo() {
	this->ninfo  = new Queue <Nationality *>  ();
}

NationalityInfo::~NationalityInfo() {
	cout << "~ Nationality" << endl;

	while ( ! this->ninfo->empty()) {
		Nationality *by = this->ninfo->front();
		this->ninfo->dequeue();
		delete by;
	}
	delete this->ninfo;
}

void NationalityInfo::putNationalityInfo(string country) {
	this->separateCountries  (country);
}

void NationalityInfo::show() {
	cout << "[NationalityInfo] show " << endl;
	cout << "---------------" << endl << endl;

	Queue<Nationality *> *tmp = new Queue<Nationality *> ();

	while ( ! this->ninfo->empty()) {
		Nationality *by = this->ninfo->front();
		this->ninfo->dequeue();
		tmp->enqueue(by);

		by->show();
	}

	while ( ! tmp->empty()) {
		Nationality *by = tmp->front();
		tmp->dequeue();
		this->ninfo->enqueue(by);
	}

	delete tmp;
}
