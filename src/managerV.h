/*
 * managerV.h
 *
 *  Created on: 18 abr. 2018
 *      Author: usuario
 */

#ifndef MANAGERV_H_
#define MANAGERV_H_

#include "via.h"
#include "list.h"

class ViaManager{

private:

	IList <Via*> *lVia;

public:

	ViaManager();
	~ViaManager();
	void showInOrder ();
};



#endif /* MANAGERV_H_ */
