/*
 * managerV.cpp
 *
 *  Created on: 18 abr. 2018
 *      Author: usuario
 */


#include "managerV.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

ViaManager::ViaManager(){
	this->lVia = new IList<Via *> ();

	ifstream ifs;
	ifs.open("via.csv");

	if (ifs.fail()) {
		cerr << "ERROR: opening the file" << endl;
		return;
	}

	string      code;
	string      name;
	string      neigh;
	string      length;
	string      type;


	while (!ifs.eof()) {

		getline(ifs, neigh, '#');
		getline(ifs, name, '#');
		getline(ifs, length, '#');
		getline(ifs, type, '#');
		getline(ifs, code, '#');

		int c = atoi(code.c_str());
		int l = atoi(length.c_str());



		Via *v = new Via();
		v->putName(name);
		v->putNeigh(neigh);
		v->putType(type);
		v->putCode(c);
		v->putLength(l);



	}
}

