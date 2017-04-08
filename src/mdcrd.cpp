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
#include "pdb.h"

vector<Coordinates> mdcrd;
bool read_mdcrd ( string mdcrdfilename, int number_of_atoms ) {

    int size;

    ifstream parmfile( mdcrdfilename );

    size=0;

    if (!(parmfile.is_open())) {

        return false;
    } else {
        mdcrd.push_back(Coordinates());
        for( int i = 0; size < ( number_of_atoms + 1 ); i++ ) {

            string firstresiduename;

            if ( i == 0  ){

                parmfile >> firstresiduename;
                continue;

            } else if ( parmfile >> mdcrd[size].X >> mdcrd[size].Y >> mdcrd[size].Z ) {

                cout << setw(8) << left << mdcrd[size].X
                     << setw(8) << left << mdcrd[size].Y
                     << setw(8) << left << mdcrd[size].Z << endl;

                size++;
                mdcrd.push_back(Coordinates());

            } else {

                break;
            }
        }
    return true;
    }
}
