/*
 * education.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */

#include "education.h"

Education::Education(string educationLevel,int number){
	this->number=number;
	this->educationLevel=educationLevel;
}

void Education::show(){
	cout << this->educationLevel << " -> " << this->number << endl;
}


