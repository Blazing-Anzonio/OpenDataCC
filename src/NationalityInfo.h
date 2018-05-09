/*
 * NationalityInfo.h
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */
#ifndef NationalityINFO_H_
#define NationalityINFO_H_
#include "queue.h"
#include "Nationality.h"

using namespace std;

class NationalityInfo {

private:

	Queue <Nationality *>   *ninfo;

	void separateCountries (string country);

public:

	NationalityInfo ();
	~NationalityInfo ();

	void putNationalityInfo (string country);

	void show ();

};




#endif /* BIRTHPLACES_H_ */




