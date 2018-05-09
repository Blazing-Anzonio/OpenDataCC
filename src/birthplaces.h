/*
 * birhtplaces.h
 *
 *  Created on: 4 abr. 2018
 *      Author: usuario
 */

#ifndef BIRTHPLACES_H_
#define BIRTHPLACES_H_
#include "queue.h"
#include "birthplace.h"

using namespace std;

class BirthPlaces {

private:

	Queue <BirthPlace *>   *bplaces;

	void separatePlaces (string birthplaces);

public:

	 BirthPlaces ();
	~BirthPlaces ();

	void putBirthPlaces (string places);

	void show ();

};




#endif /* BIRTHPLACES_H_ */
