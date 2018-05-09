/*
 * EducationInfo.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: usuario
 */


#include "educationInfo.h"
#include <cstdlib>
#include <vector>

//PRIVATE OPERATIONS

// Separate fields with multiple items with the format:
//   educationLevel1 (number1) ; educationLevel2 (number2) ; educationLevel3 (number3)
void EducationInfo::separateEducation (string educationLevel) {

    const char DELIM = ';';
    std::string::size_type pos1;
    std::string::size_type pos2;
    std::string::size_type beg_index, end_index;

    beg_index = 0;
    while (beg_index != std::string::npos) {

        end_index = educationLevel.find_first_of(DELIM, beg_index);
        if (end_index == std::string::npos)
            end_index = educationLevel.length();

        string item = educationLevel.substr(beg_index, end_index - beg_index);

        // Extract educationLevel and number of an item:  Bachiller (7)
        pos1 = item.find('(');
        item.erase(pos1, 1);

        string l = item.substr(0, pos1);

        pos2 = item.find(')');
        item.erase(pos2, 1);

        string n = item.substr(pos1, pos2 - pos1);

        Education *el = new Education (l, atoi(n.c_str()));
        this->edu->enqueue(el);

        beg_index = educationLevel.find_first_not_of(DELIM, end_index);
    }
}
//PUBLIC INTERFACE

EducationInfo::EducationInfo (){
	this->edu = new Queue <Education*>();
}

EducationInfo::~EducationInfo (){
	cout << "~ EducationInfo" << endl;

	while ( ! this->edu->empty()) {
		Education *by = this->edu->front();
		this->edu->dequeue();
		delete by;
	}
	delete this->edu;
}

void EducationInfo::putEducation (string education) {
	this->separateEducation  (education);
}

void EducationInfo::show () {

	cout << "[Education] show " << endl;
	cout << "---------------" << endl << endl;

	Queue<Education *> *tmp = new Queue <Education *> ();

	while ( ! this->edu->empty()) {
		Education *by = this->edu->front();
		this->edu->dequeue();
		tmp->enqueue(by);

		by->show();
	}

	while ( ! tmp->empty()) {
		Education *by = tmp->front();
		tmp->dequeue();
		this->edu->enqueue(by);
	}

	delete tmp;
}

