#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

using namespace std;

#include "pdb.h"

bool Pdb::read_pdb ( string pdbfilename, Atom db[1000], int & size ) {

    ifstream ifile( pdbfilename );
    if ( !ifile.is_open() ) return false;
    size = 0;

    while ( size < 1000 ) {

        if ( !(ifile >> db[size].atom_type >> db[size].atom_number >> db[size].element >> db[size].type >> db[size].residue_number >> db[size].x_coord >> db[size].y_coord >> db[size].z_coord >> db[size].ligand_distance >> db[size].score ) )
            break;
        size++;
        }
    return true;
}

Pdb::Atom pdb[1000];
int Pdb::number_of_atoms;
string Pdb::pdbfilename;
