/*
 * Education.h
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */

#ifndef EDUCATION_H_
#define EDUCATION_H_
#include <string>
#include <iostream>
using namespace std;

class Education {

private:
	int number;
	string educationLevel;

public:
	Education (string educationLevel,int number);

	void show ();
};



#endif /* EDUCATION_H_ */
