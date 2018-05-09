/*
 * manager.h
 *
 *  Created on: 13 mar. 2018
 *      Author: jarico
 */

#ifndef MANAGERN_H_
#define MANAGERN_H_

#include "stack.h"
#include "neighborhood.h"

using namespace std;

class NeighManager {

private:

	Stack<Neighborhood *> *sNeighs;

	void showStackRec (Stack<Neighborhood *> *s);

public:

	 NeighManager ();
	~NeighManager ();

	void addNeigh (Neighborhood *n);
	void loadCensus();
	void show     ();
	void showVias (Neighborhood *n);
};

//Implementar

#endif /* MANAGERN_H_ */
