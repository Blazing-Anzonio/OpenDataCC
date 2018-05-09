//============================================================================
// Name        : UI.h
// Author      : profesores de la asignatura EDI
// Version     : curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================


#ifndef UI_H_
#define UI_H_
#include "managerN.h"
#include "timer.h"
#include "via.h"
#include "neighborhood.h"


class UI {

private:

	int  menu  ();
	void exec  ();

public:

	 UI();
	~UI();
};

#endif /* UI_H_ */
