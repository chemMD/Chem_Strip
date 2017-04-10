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
vector<Coordinates> per_box_bound;

bool read_mdcrd ( string mdcrdfilename, int time_steps, int number_of_atoms ) {

    int size;

    ifstream parmfile( mdcrdfilename );

    if (!(parmfile.is_open())) {

        return false;
    } else {


        size =0;
        for( int j = 1; j < (time_steps + 1); j++ ) {
            for( int i = 0; size < ( ( number_of_atoms + 1 ) * j ); i++ ) {

                string firstresiduename;
                mdcrd.push_back(Coordinates());
                if ( j == 1 && i == 0  ){

                    parmfile >> firstresiduename;
                    continue;

                } else if ( parmfile >> mdcrd[size].X >> mdcrd[size].Y >> mdcrd[size].Z ) {
                    size++;
                }
                if ( size == ( number_of_atoms + 1 ) * j ) {
                    per_box_bound.push_back(Coordinates());
                    per_box_bound[j-1].X = mdcrd[size -1 ].X;
                    per_box_bound[j-1].Y = mdcrd[size -1 ].Y;
                    per_box_bound[j-1].Z = mdcrd[size -1 ].Z;
                    cout << per_box_bound[j-1].X << per_box_bound[j-1].Y << per_box_bound[j-1].Z << endl;
                    mdcrd.pop_back();
                }
            }
        }
    return true;
    }
}
bool write_mdcrd ( string mdcrdoutname ) {
    cout << "Writing stripped mdcrd file: "<< mdcrdoutname << endl;
    ofstream ofile;
    ofile.open( mdcrdoutname );
    if ( !ofile.is_open() ) {
        return false;
    }
    int i = 0;
    for ( vector<Coordinates>::iterator it = mdcrd.begin(); it < (mdcrd.end() - 1); it++) {
            ofile << setw(8) << left << mdcrd[i].X
                  << setw(8) << left << mdcrd[i].Y
                  << setw(8) << left << mdcrd[i].Z << endl;
        i++;
    }
    return true;
}
