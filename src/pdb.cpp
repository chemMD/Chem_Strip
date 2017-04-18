/**
 * @short   process PDB
 * @file    pdb.cpp
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This file contains the prototypes read_pdb, check_pdb and write_pdb. The rea\
d_pdb
* function is a boolean function that parses the PDB input file stream into a \
vector
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
#include "pdb.h"

/**
 * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: This read_pdb function utilizes the Atom struct
 *                   found in pdb.h and the vector-struct pdb declared
 *                   in main program.
 *
 * Return             true on success
 *
 */

bool read_pdb ( string pdbfilename, int & size, vector<Atom> & pdb ) {

    ifstream ifile( pdbfilename );
    string ter = "TER";

    size = 0;

    if ( !ifile.is_open() ) {

        return false;
    }

    pdb.push_back(Atom());

    for ( int i = 0; i < 10000; i++ ) {

        ifile >> pdb[size].atom_type ;

        if ( pdb[size].atom_type == ter ) {

            continue;

        } else if ( ifile >> pdb[size].atom_number
                          >> pdb[size].element
                          >> pdb[size].type
                          >> pdb[size].residue_number
                          >> pdb[size].x_coord
                          >> pdb[size].y_coord
                          >> pdb[size].z_coord
                          >> pdb[size].ligand_distance
                          >> pdb[size].score) {

            pdb.push_back(Atom());
            size++;

        } else {

            break;
        }
    }

    return true;
}

/**
 * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: This check_pdb function utilizes the Atom struct
 *                   found in pdb.h. It also uses the vector-struct pdb, vector-int
 *                   rdf_solute_index and vector-int rdf_solvent_index
 *                   defined/declared in the main program.
 *
 * Return             true on success
 *
 */

bool check_pdb ( string rdf_solute, string rdf_solute_atom,
        string rdf_solvent, string rdf_solvent_atom, vector<Atom> & pdb,
        vector<int> & rdf_solute_index,int & rdf_solute_it,
        vector<int> & rdf_solvent_index, int & rdf_solvent_it ) {

    cout << "Locating rdf atoms within file: " << endl;

    int i = 0;
    rdf_solute_it = 0;

    for ( vector<Atom>::iterator it = pdb.begin(); it < pdb.end(); it++) {

        rdf_solute_index.push_back(int());

        if ( !( pdb[i].type == rdf_solute && pdb[i].element == rdf_solute_atom ) ) {

            i++;
            continue;

        } else {
            cout << setw(5) << left << pdb[i].atom_type
              << setw(6) << right << pdb[i].atom_number
              << setw(4) << left << pdb[i].element
              << setw(5) << right << pdb[i].type
              << setw(6) << right << pdb[i].residue_number
              << setw(12) << right << pdb[i].x_coord
              << setw(8) << right << pdb[i].y_coord
              << setw(8) << right << pdb[i].z_coord
              << setw(6) << right << pdb[i].ligand_distance
              << setw(6) << right << pdb[i].score
              << endl;

            rdf_solute_index.push_back(int());
            rdf_solute_index[rdf_solute_it] = i;
            cout << rdf_solute_index[rdf_solute_it] << endl;
            rdf_solute_it++;
            i++;
        }
    }

    i = 0;
    rdf_solvent_it = 0;

    for ( vector<Atom>::iterator it = pdb.begin(); it < pdb.end(); it++) {

        rdf_solvent_index.push_back(int());

        if ( !( pdb[i].type == rdf_solvent && pdb[i].element == rdf_solvent_atom ) ) {

            i++;
            continue;

        } else {
            cout << setw(5) << left << pdb[i].atom_type
              << setw(6) << right << pdb[i].atom_number
              << setw(4) << left << pdb[i].element
              << setw(5) << right << pdb[i].type
              << setw(6) << right << pdb[i].residue_number
              << setw(12) << right << pdb[i].x_coord
              << setw(8) << right << pdb[i].y_coord
              << setw(8) << right << pdb[i].z_coord
              << setw(6) << right << pdb[i].ligand_distance
              << setw(6) << right << pdb[i].score
              << endl;

            rdf_solvent_index.push_back(int());
            rdf_solvent_index[rdf_solvent_it] = i;
            cout << rdf_solvent_index[rdf_solvent_it] << endl;
            rdf_solvent_it++;
            i++;
        }

    }


    if (rdf_solute_it == 0 ) {

        cout << "No solute present" << endl;
        return false;

    } else if (rdf_solvent_it == 0) {

        cout << "No solvent present" << endl;
        return false;

    } else {

    return true;
    }
}

/**
 * Author:            Caleb Gallops and Dennis Kennetz
 *
 * Short description: The write_pdb function utilizes the vector-struct
 *                   pdb and the vector-int strip_index defined/declared in the 
 *                   main program.
 *
 * Return             true on success
 *
 */

bool write_pdb ( string pdboutname, string stripcommand, vector<Atom> & pdb, vector<int> & strip_index ) {

    cout << "Writing stripped pdb file: " << endl;
    ofstream ofile;

    ofile.open( pdboutname );
    if ( !ofile.is_open() ) {
        return false;
    }

    int i = 0;
    int strip_index_it = 0;

    for ( vector<Atom>::iterator it = pdb.begin(); it < pdb.end(); it++) {

        if (!(pdb[i].type == stripcommand)) {
            ofile << setw(5) << left << pdb[i].atom_type
              << setw(6) << right << pdb[i].atom_number
              << setw(4) << left << pdb[i].element
              << setw(5) << right << pdb[i].type
              << setw(6) << right << pdb[i].residue_number
              << setw(12) << right << pdb[i].x_coord
              << setw(8) << right << pdb[i].y_coord
              << setw(8) << right << pdb[i].z_coord
              << setw(6) << right << pdb[i].ligand_distance
              << setw(6) << right << pdb[i].score
              << endl;

        } else {

            strip_index.push_back(int());
            strip_index[strip_index_it] = i;
            strip_index_it++;
        }

        i++;
    }

    return true;
}
