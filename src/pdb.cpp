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

bool Pdb::read_pdb ( string pdbfilename, Atom pdb[10000], int & size ) {
    ifstream ifile( pdbfilename );
    string ter = "TER";
    if ( !ifile.is_open() ) return false;
    size = 0;
    for ( int i = 0; i < 10000; i = i + 1 ) {
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
	    size++;
        } else { 
	    break;
        }
    }
    return true;
}

bool Pdb::write_pdb ( string pdboutname, string stripcommand, Atom pdb[10000], int number_of_atoms) {

    ofstream ofile( pdboutname );
    
    if ( !ofile.is_open() ) {
        return false;
    }
    for ( int i = 0; i < number_of_atoms; i++ ) {
        if (!(pdb[i].type == stripcommand)) {
	    ofile << setw(9) << left << pdb[i].atom_type
	          << setw(4) << left << pdb[i].atom_number
	      << setw(6) << left << pdb[i].element
	      << setw(7) << left << pdb[i].type
	      << setw(8) << left << pdb[i].residue_number
	      << setw(8) << left << pdb[i].x_coord
	      << setw(8) << left << pdb[i].y_coord
	      << setw(8) << right << pdb[i].z_coord
	      << setw(6) << right << pdb[i].ligand_distance
	      << setw(6) << right << pdb[i].score
	      << endl;

        }
    }
    return true;
}
Pdb::Atom pdb[10000];
int Pdb::number_of_atoms;
string Pdb::pdbfilename;
string Pdb::pdboutname;
string Pdb::stripcommand;
