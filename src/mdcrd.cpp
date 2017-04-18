/**
 * @short   process MDCRD
 * @file    mdcrd.cpp
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This file contains the prototypes read_mdcrd, check_mdcrd and write_mdcrd. T\
he read_mdcrd
* function is a boolean function that parses the MDCRD input file stream into \
a vector
* of a struct.
*/


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

string firstresiduename;

bool read_mdcrd ( string mdcrdfilename, int time_steps,
        int number_of_atoms,vector<Coordinates> & mdcrd,
        vector<Coordinates> & per_box_bound ) {

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

bool check_mdcrd ( string mdcrdoutname, int time_steps, int number_of_atoms,
        vector<int> & rdf_solute_index,vector<int> & rdf_solvent_index, vector<Coordinates> & mdcrd,
        vector<Coordinates> & rdf_solute_coord, vector<Coordinates> & rdf_solvent_coord ) {

    cout << "Writing stripped mdcrd file: "<< mdcrdoutname << endl;

    int i = 0;
    int rdf_solute_it;
    int rdf_solvent_it;

    for ( int j = 1; j < 3; j++ ) {

        rdf_solute_it = 0;
        rdf_solvent_it = 0;

        for ( vector<Coordinates>::iterator it = mdcrd.begin(); i < ( number_of_atoms * j ); it++) {

            if ( i == ( rdf_solute_index[rdf_solute_it] + ( number_of_atoms * (j -1) ) ) ) {

                rdf_solute_coord.push_back(Coordinates());
                rdf_solute_coord[rdf_solute_it].X = mdcrd[i].X;
                rdf_solute_coord[rdf_solute_it].Y = mdcrd[i].Y;
                rdf_solute_coord[rdf_solute_it].Z = mdcrd[i].Z;

                cout << rdf_solute_coord[rdf_solute_it].X
                     << rdf_solute_coord[rdf_solute_it].Y
                     << rdf_solute_coord[rdf_solute_it].Z << endl;

                rdf_solute_it++;
                i++;

            } else if ( i == ( rdf_solvent_index[rdf_solvent_it] + ( number_of_atoms * (j -1) ) ) ) {

                rdf_solvent_coord.push_back(Coordinates());
                rdf_solvent_coord[rdf_solvent_it].X = mdcrd[i].X;
                rdf_solvent_coord[rdf_solvent_it].Y = mdcrd[i].Y;
                rdf_solvent_coord[rdf_solvent_it].Z = mdcrd[i].Z;

                cout << rdf_solvent_coord[rdf_solvent_it].X
                     << rdf_solvent_coord[rdf_solvent_it].Y
                     << rdf_solvent_coord[rdf_solvent_it].Z << endl;

                rdf_solvent_it++;
                i++;

            } else {

                i++;
                continue;
            }
        }
    }
    return true;
}

bool write_mdcrd ( string mdcrdoutname, int time_steps,
        int number_of_atoms, vector<int> & strip,
        vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound ) {

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
        cout<< strip[strip_index_it] << endl;

        for ( vector<Coordinates>::iterator it = mdcrd.begin(); i < ( number_of_atoms * j ); it++) {

            if (!( i == ( strip[strip_index_it] + ( number_of_atoms * (j -1) ) ) ) ) {

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
