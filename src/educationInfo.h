/*
 * EducationInfo.h
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */

#ifndef EDUCATIONINFO_H_
#define EDUCATIONINFO_H_

#include "queue.h"
#include "education.h"


class EducationInfo {

private:
	Queue<Education*> *edu;
	void separateEducation (string educationLevel);

public:
	EducationInfo();
	~EducationInfo();

	void putEducation (string education);
	void show();
};



#endif /* EDUCATIONINFO_H_ */
