/*
 * gestorbarrios.cpp
 *
 *  Created on: 13 mar. 2018
 *      Author: jarico
 */

#include "managerN.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;



//  PRIVATE OPERATIONS
void NeighManager::showStackRec (Stack<Neighborhood *> *s) {

	Neighborhood *b = NULL;

	if (!s->empty()) {

		s->top(b);

		s->pop();

		this->showStackRec(s);

		b->show();
		s->push(b);
	}
}





// PUBLIC INTERFACE


NeighManager::NeighManager () {

	this->sNeighs = new Stack<Neighborhood *> ();

	ifstream ifs;
	ifs.open("Neighborhood.csv");

	if (ifs.fail()) {
		cerr << "ERROR: opening the file" << endl;
		return;
	}

	string name;
	string district;

	while (!ifs.eof()) {

		getline(ifs, name, '#');

		if (!ifs.eof()) {
			getline(ifs, district);

			Neighborhood *b = new Neighborhood();
			b->putName(name);
			b->putDistrict(district);

			this->sNeighs->push(b);

		}
	}
}


NeighManager::~NeighManager () {

	Neighborhood *b = NULL;

	while ( ! this->sNeighs->empty()) {
		this->sNeighs->top(b);
		this->sNeighs->pop();
		delete b;
	}

	delete (this->sNeighs);
}

void NeighManager::addNeigh (Neighborhood *n) {
	this->sNeighs->push(n);
}

void NeighManager::show () {
	this->showStackRec(this->sNeighs);
}

void NeighManager::loadCensus (){
	ifstream ifs;
	string fname = "census.csv";

	ifs.open(fname.c_str());

	if (ifs.fail()) {
		cerr << "ERROR: opening file " << fname << endl;
	}

	while (!ifs.eof()) {

		string code;
		string byears;
		string bplaces;
		string educational;
		string nationalities;
		string females;
		string males;
		string year;

		getline(ifs, code, '#');

		if (!ifs.eof()) { // This is for avoiding an additional line reading

			getline(ifs, byears,        '#');
			getline(ifs, bplaces,       '#');
			getline(ifs, educational,   '#');
			getline(ifs, females,       '#');
			getline(ifs, males,         '#');
			getline(ifs, nationalities, '#');
			getline(ifs, year);

			int c = atoi(code.c_str());
			int f = atoi(females.c_str());
			int m = atoi(males.c_str());
			int y = atoi(year.c_str());

			//Via *v = lv->find(c);  // Search for the via using code
			// Temporal code
			Via *v = new Via();
			v->putCode (c);
			v->putBirthYears(byears);
			v->putBirthplaces(bplaces);
			v->putEducationInfo((educational));
			v->putFemale(f);
			v->putMale(m);
			v->putNationalityInfo(nationalities);
			v->putYear(y);

			v->show();

			delete v;

		}
	}

	ifs.close();


}

void showVias (Stack<Neighborhood *> *s){

}
