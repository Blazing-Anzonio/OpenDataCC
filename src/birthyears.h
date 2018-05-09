/*
 * birthyears.h
 *
 *  Created on: 16 mar. 2018
 *      Author: jarico
 */

#ifndef BIRTHYEARS_H_
#define BIRTHYEARS_H_

#include "queue.h"
#include "birthyear.h"

using namespace std;


class BirthYears {

private:

	Queue <BirthYear *>   *byears;

	void separateYears  (string birthyears);

public:

	 BirthYears ();
	~BirthYears ();

	void putBirthYears  (string years);

	void show ();

};

#endif /* BIRTHYEARS_H_ */
