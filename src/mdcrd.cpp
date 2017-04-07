#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

using namespace std;

#include "input.h"
#include "mdcrd.h"

int Mdcrd::number_of_coordinates;
Mdcrd::Coordinates mdcrd[5272];
string Mdcrd::mdcrdfilename;
string Mdcrd::mdcrdoutname;

bool Mdcrd::read_mdcrd ( string mdcrdfilename, Coordinates mdcrd[5272], int & size ) {

    ifstream parmfile( mdcrdfilename );

    size=0;

    if (!(parmfile.is_open())) {

        return false;

    } else {

        for( int i = 0; i < 5272; i = i + 1 ) {

            parmfile >> mdcrd[size].X;

            if ( i == 1 ) {

                continue;

            } else if (parmfile >> mdcrd[size].X >> mdcrd[size].Y >> mdcrd[size].Z) {

                cout << setw(8) << left << mdcrd[size].X
                     << setw(8) << left << mdcrd[size].Y
                     << setw(8) << left << mdcrd[size].Z << endl;
                size++;

            } else {

                break;
            }
        }

    return true;
    }
}
