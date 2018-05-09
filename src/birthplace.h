/*
 * birthplace.h
 *
 *  Created on: 21 mar. 2018
 *      Author: usuario
 */

#ifndef BIRTHPLACE_H_
#define BIRTHPLACE_H_
#include <string>
#include <iostream>
using namespace std;

class BirthPlace {

private:
	string place;
	int number;
	string province;

public:
	BirthPlace (string place, string province, int number);

	void show();
};



#endif /* BIRTHPLACE_H_ */
