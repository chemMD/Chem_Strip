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

string firstresiduename;

bool read_mdcrd ( string mdcrdfilename, int time_steps, int number_of_atoms ) {

    int size;

    ifstream parmfile( mdcrdfilename );

    if (!(parmfile.is_open())) {

        return false;

    } else {

        size =0;

        for( int j = 1; j < (time_steps + 1); j++ ) {

            for( int i = 0; size < ( ( number_of_atoms + 1 ) * j ); i++ ) {

                mdcrd.push_back(Coordinates());

                if ( j == 1 && i == 0  ){

                    parmfile >> firstresiduename;
                    continue;

                } else if ( size == ( number_of_atoms ) * j ) {

                    per_box_bound.push_back(Coordinates());
                    parmfile >> per_box_bound[j-1].X
                             >> per_box_bound[j-1].Y
                             >> per_box_bound[j-1].Z;
                    break;

                } else if ( parmfile >> mdcrd[size].X >> mdcrd[size].Y >> mdcrd[size].Z ) {

                    size++;
                }

            }

        mdcrd.pop_back();
        }

    return true;
    }
}

bool write_mdcrd ( string mdcrdoutname, int time_steps, int number_of_atoms) {

    cout << "Writing stripped mdcrd file: "<< mdcrdoutname << endl;

    ofstream ofile;

    ofile.open( mdcrdoutname );

    if ( !ofile.is_open() ) {
        return false;
    }

    int i = 0;
    int strip_index_it;

    vector<int> x_print_form;
    vector<int> y_print_form;
    vector<int> z_print_form;

    for (int k = 0 ; k < ( ( number_of_atoms / 3 ) * time_steps ); k++) {

        x_print_form.push_back(int());
        y_print_form.push_back(int());
        z_print_form.push_back(int());

        x_print_form[k] = 3 + ( 10 * k );
        y_print_form[k] = 6 + ( 10 * k );
        z_print_form[k] = 9 + ( 10 * k );

    }

    int x;
    int y;
    int z;

    ofile << setw(80) << left << firstresiduename << endl;

    for ( int j = 1; j < 3; j++ ) {

        x = 0;
        y = 0;
        z = 0;

        strip_index_it = 0;
        cout<< strip_index[strip_index_it] << endl;

        for ( vector<Coordinates>::iterator it = mdcrd.begin(); i < ( number_of_atoms * j ); it++) {

            if (!( i == ( strip_index[strip_index_it] + ( number_of_atoms * (j -1) ) ) ) ) {

                if ( i == ( x_print_form[x] + number_of_atoms * ( j - 1 ) ) ) {

                    ofile << setw(8) << right << mdcrd[i].X << '\n'
                          << setw(8) << right << mdcrd[i].Y
                          << setw(8) << right << mdcrd[i].Z;
                    x++;

                } else if ( i == ( y_print_form[y] + number_of_atoms * ( j - 1 ) ) ) {

                    ofile << setw(8) << right << mdcrd[i].X
                          << setw(8) << right << mdcrd[i].Y << '\n'
                          << setw(8) << right << mdcrd[i].Z;
                    y++;

                } else if ( i == ( z_print_form[z] + number_of_atoms * ( j - 1 ) ) ) {

                    ofile << setw(8) << right << mdcrd[i].X
                          << setw(8) << right << mdcrd[i].Y
                          << setw(8) << right << mdcrd[i].Z << '\n';
                    z++;

                } else {

                    ofile << setw(8) << right << mdcrd[i].X
                          << setw(8) << right << mdcrd[i].Y
                          << setw(8) << right << mdcrd[i].Z;
                }

            i++;

            } else {

                strip_index_it++;
                i++;
            }
        }

        ofile << endl
              << setw(8) << right << per_box_bound[j-1].X
              << setw(8) << right << per_box_bound[j-1].Y
              << setw(8) << right << per_box_bound[j-1].Z << endl;
    }
    return true;
}
