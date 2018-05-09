/*
 * via.h
 *
 *  Created on: 7 mar. 2018
 *      Author: jarico
 */

#ifndef VIA_H_
#define VIA_H_

#include "birthyears.h"
#include "birthplaces.h"
#include "educationInfo.h"
#include "NationalityInfo.h"

#include <string>
using namespace std;

class Via {

private:

	int         code;
	string      name;
	string      neigh;
	float       length;
	string      type;
	int 		males;
	int			females;
	int			year;

	BirthYears       *birthYears;
	BirthPlaces		 *birthPlaces;
	EducationInfo		*eduInfo;
	NationalityInfo  *natioInfo;


public:

	 Via ();
	~Via ();

	void   putCode       (int code);
	void   putName       (string name);
	void   putLength     (float length);
	void   putMale		(int male);
	void   putFemale	(int female);
	void   putYear		(int year);
	void   putNeigh     (string neigh);
	void   putType      (string type);

	string getName       ();
	float  getLength     ();

	void   putBirthYears (string byears);
	void   putBirthplaces (string place);
	void   putEducationInfo (string level);
	void   putNationalityInfo (string country);

	void   show         ();
};

#endif /* VIA_H_ */
