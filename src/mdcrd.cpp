/**
 * @short   process MDCRD
 * @file    mdcrd.cpp
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This file contains the prototypes read_mdcrd, check_mdcrd and write_mdcrd. The read_mdcrd
 * function is a boolean function that parses the MDCRD input file stream into a vector
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

/**
 *  *   * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: This read_pdb function utilizes the Atom struct
 *                   found in pdb.h and the vector-struct pdb declared
 *                   in struct Input. It reads the MDCRD file for all of
 *                   the atom coordinates.
 *
 * Return             true on success
 *
 */
bool read_mdcrd ( string mdcrdfilename, int time_steps,
        int number_of_atoms,vector<Coordinates> & mdcrd,
        vector<Coordinates> & per_box_bound, ofstream& log_file ) {

    cout << "Reading MDCRD file ..." << endl;
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

        cout << "MDCRD file has been read." << endl <<endl;
        log_file << "*************************************************************" << endl
                << "Reading mdcrd file..." << endl
                << "MDCRD file name: "<< mdcrdfilename << endl
                << "Number of time steps to be evaluated: "<< time_steps << endl
                << "Starting periodic boundaries: " << per_box_bound[0].X << " "
                << per_box_bound[0].Y << " " << per_box_bound[0].Z << endl
                << "Ending periodic boundaries: " << per_box_bound[time_steps-1].X << " "
                << per_box_bound[time_steps-1].Y << " "<< per_box_bound[time_steps-1].Z << endl
                << "MDCRD file successfully read" << endl
                << "*************************************************************" << endl;
        return true;
    }
}

/**
 * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: This check_mdcrd function utilizes the Atom struct
 *                   found in pdb.h. It also uses the vector-struct pdb, vector-int
 *                   rdf_solute_index and vector-int rdf_solvent_index
 *                   defined/declared in the main program. It saves all of the solute
 *                   and solvent coordinates into vectors.
 *
 * Return             true on success
 *
 */

bool check_mdcrd ( string mdcrdoutname, int time_steps, int number_of_atoms,
        vector<int> & rdf_solute_index,vector<int> & rdf_solvent_index,
        vector<Coordinates> & mdcrd, vector<Coordinates> & rdf_solute_coord,
        vector<Coordinates> & rdf_solvent_coord, ofstream& log_file ) {

    cout << "Checking " << mdcrdoutname << " for solute and solvent ..." << endl;

    int i = 0;
    int rdf_solute_it;
    int rdf_solvent_it;

    for ( int j = 1; j < ( time_steps + 1 ); j++ ) {

        rdf_solute_it = 0;
        rdf_solvent_it = 0;

        for ( vector<Coordinates>::iterator it = mdcrd.begin(); i < ( number_of_atoms * j ); it++ ) {

            if ( i == ( rdf_solute_index[rdf_solute_it] + ( number_of_atoms * (j -1) ) ) ) {

                rdf_solute_coord.push_back(Coordinates());
                rdf_solute_coord[rdf_solute_it].X = mdcrd[i].X;
                rdf_solute_coord[rdf_solute_it].Y = mdcrd[i].Y;
                rdf_solute_coord[rdf_solute_it].Z = mdcrd[i].Z;

                rdf_solute_it++;
                i++;

            } else if ( i == ( rdf_solvent_index[rdf_solvent_it] + ( number_of_atoms * (j -1) ) ) ) {

                rdf_solvent_coord.push_back(Coordinates());
                rdf_solvent_coord[rdf_solvent_it].X = mdcrd[i].X;
                rdf_solvent_coord[rdf_solvent_it].Y = mdcrd[i].Y;
                rdf_solvent_coord[rdf_solvent_it].Z = mdcrd[i].Z;

                rdf_solvent_it++;
                i++;

            } else {

                i++;
                continue;
            }
        }
    }

    cout << "MDCRD file has been checked." << endl << endl;
    log_file << "*************************************************************" << endl
            << "Checking and evaluating MDCRD file..." << endl
            << "Number of time steps being evaluated: "<< time_steps << endl
            << "Number of atoms per time step: "<< number_of_atoms << endl
            << "Number of solute atoms per time step: "<< rdf_solute_it << endl
            << "Number of solvent atoms per time step: "<< rdf_solvent_it << endl
            << "MDCRD successfully evaluated "<< endl
            << "*************************************************************" << endl;
    return true;
}

/**
 * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: The write_mdcrd function utilizes time_steps, number_of_atoms and strip_index
 *                   (declared in the struct Box). It also uses the vector-struct mdcrd and vector-struct
 *                   per_box_bound (declared in struct Trajectory). It writes the stripped MDCRD file.
 *
 * Return             true on success
 *
 */

bool write_mdcrd ( string mdcrdoutname, int time_steps, int number_of_atoms, vector<int> & strip,
        vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound, ofstream& log_file ) {

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

    for ( int j = 1; j < ( time_steps + 1 ) ; j++ ) {

        x = 0;
        y = 0;
        z = 0;

        strip_index_it = 0;

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

    cout << "Stripped MDCRD file has been written." << endl << endl;
    log_file << "*************************************************************" << endl
            << "Writing stripped MDCRD file..." << endl
            << "Number of time steps being written: "<< time_steps << endl
            << "Number of atoms removed from each time steps: "<< strip_index_it << endl
            << "Number of atoms leftover per time step: "<< ( number_of_atoms - strip_index_it ) * time_steps << endl
            << "Total number of atoms removed: "<< strip_index_it << endl
            << "Total number of atoms leftover: "<< ( number_of_atoms - strip_index_it ) * time_steps << endl
            << "Stripped MDCRD successfully written "<< endl
            << "*************************************************************" << endl;
    return true;
}
