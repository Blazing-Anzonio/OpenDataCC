/*
 * neighborhood.h
 *
 *  Created on: 27 feb. 2018
 *      Author: jarico
 */

#ifndef NEIGHBORHOOD_H_
#define NEIGHBORHOOD_H_

#include "via.h"

#include <string>
#include <iostream>
using namespace std;

class Neighborhood {

private:

	string  name;
	string  district;

	Via*  streets  [2000];
	int   count;


public:

	 Neighborhood ();
	~Neighborhood ();

	void   putName       (string name);
	void   putDistrict   (string district);
	string getName       ();
	void   getDistrict   (string &district);
	void   show          ();

	void   addVia        (Via* v);
	void   showVias      ();

	void   getLongestVia (Via* &v);
	void   getVia        (string name, Via* &v);
};

#endif /* NEIGHBORHOOD_H_ */
