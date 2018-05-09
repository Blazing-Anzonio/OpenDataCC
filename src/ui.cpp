//============================================================================
// Name        : UI.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#include "ui.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;



UI::UI() {
	// Build the class UI invokes exec.
	exec();
}


void UI::exec() {


	double t_start, t_end;
	int option;

	// Loading data
	t_start = Time::getTime();
	cout << "Loading data ... " << endl;

	t_end = Time::getTime();
	cout << fixed << setprecision(6) << "Time: " << t_end - t_start << " ms." << endl;
	NeighManager *man = new NeighManager();

	bool finish = false;
	do {
		option = menu();
		switch (option) {
		case 1:
		man->loadCensus();
			break;

		case 2:
			// TBD: algorithm 2
			//We ask for a neighborhood and we show in ALPHABETICAL ORDER all the street of the neighborhood
			break;

		case 3:
			// TBD: algorithm 3
			//Show all the street that is on more tha one neightborhood and separated by its neighborhood
			break;

		case 4:
			// TBD: algorithm 4
			//Show the number of people depending on the ages (in group of 10)
			break;

		case 5:
			// TBD: algorithm 5
			//Show all the nationality on increasing order of the people of that nationality
			break;

		case 6:
			// TBD: algorithm 6

			break;

		case 7:
			// TBD: algorithm 7
			break;

		case 8:
			// TBD: algorithm 8
			break;

		case 9:
			// TBD: algorithm 9
			break;

		case 10:
			// TBD: algorithm 10
			break;

		case 11:
			// TBD: algorithm 11
			break;

		case 12:
			// TBD: algorithm 12
			break;

		case 0:
			finish = true;
			break;

		default:
			cerr << "ERROR: invalid option " << option << endl;
			break;
		}

	} while (! finish);
}

int UI::menu() {

	int option;

	do {
		cout << endl;
		cout << "_________________________________ MAIN MENU __________________________________"<< endl << endl;

		cout << "   1.  Loading data                                                                 "<< endl;
		cout << "   2.  Showing streets of a neighborhood                                            "<< endl;
		cout << "   3.  Showing streets of several neighborhoods                                     "<< endl;
		cout << "   4.  (add new algorithms here)                                                    "<< endl;
		cout << "   12. . . .                                                                        "<< endl;

		cout << endl;
		cout << "   0. Finish. " << endl;
		cout << " Option:  ";
		cin >> option;
		cin.ignore();

	} while ((option < 0) || (option > 13));

	return option;
}

UI::~UI() {
	// TODO delete
	cout << "Finishing ...";
}


