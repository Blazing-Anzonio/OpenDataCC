/*
 * birthplaces.cpp
 *
 *  Created on: 4 abr. 2018
 *      Author: usuario
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "birthplaces.h"
using namespace std;

// PRIVATE OPERATIONS

// Description: this operation (private) split the items in the field
// birth places of the file census.csv.
// INPUT: the field containing the birth places separated by ";"
//   Example: Talavera De La Reina (Toledo) (1); Alemania (3); No especificado (1)
// OUTPUT: A data structure (Queue attribute of the class) containing
//         BirthPlace items.
void BirthPlaces::separatePlaces (string birthplaces) {

    const char DELIM = ';';
    std::string::size_type beg_index, end_index;

    beg_index = 0;
    while (beg_index != std::string::npos) {

        end_index = birthplaces.find_first_of(DELIM, beg_index);
        if (end_index == std::string::npos)
            end_index = birthplaces.length();

        string item = birthplaces.substr(beg_index, end_index - beg_index);

        // Item format possibilities:
        // a) Talavera De La Reina (Toledo) (1)
        // b) Alemania (3)
        // c) No especificado (1)
        // cout << item << endl;

        std::string::size_type start, end;

        // First subitem
        start = 0;
        end = item.find_first_of('(', start);
        string i1 = item.substr(start, end - start);
        item.erase(start, end - start + 1);

        // Second subitem
        start = 0;
        end = item.find_first_of(')', start);
        string i2 = item.substr(start, end - start);
        item.erase(start, end - start + 1);

        // Third subitem (if exists)
        end = item.find_first_of('(', start);
        if (end != std::string::npos) { // There is a third subitem
            start = end + 1;
            end = item.find_first_of(')', start);
            string i3 = item.substr(start, end - start);

            BirthPlace *bp = new BirthPlace (i1, i2, atoi(i3.c_str()));
            bp->show();

        } else {
            BirthPlace *bp = new BirthPlace (i1, "", atoi(i2.c_str()));
            bp->show();
        }


        // Next item
        beg_index = birthplaces.find_first_not_of(DELIM, end_index);
    }
}

// PUBLIC INTERFACE

BirthPlaces::BirthPlaces () {
	this->bplaces  = new Queue <BirthPlace *>  ();
}


BirthPlaces::~BirthPlaces () {
	cout << "~ BirthPlaces" << endl;

	while ( ! this->bplaces->empty()) {
		BirthPlace *by = this->bplaces->front();
		this->bplaces->dequeue();
		delete by;
	}
	delete this->bplaces;
}


void BirthPlaces::putBirthPlaces (string places) {
	this->separatePlaces  (places);
}

void BirthPlaces::show () {

	cout << "[BirthPlace] show " << endl;
	cout << "---------------" << endl << endl;

	Queue<BirthPlace *> *tmp = new Queue<BirthPlace *> ();

	while ( ! this->bplaces->empty()) {
		BirthPlace *by = this->bplaces->front();
		this->bplaces->dequeue();
		tmp->enqueue(by);

		by->show();
	}

	while ( ! tmp->empty()) {
		BirthPlace *by = tmp->front();
		tmp->dequeue();
		this->bplaces->enqueue(by);
	}

	delete tmp;
}
