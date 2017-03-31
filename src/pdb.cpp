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

bool Pdb::read_pdb ( string pdbfilename, Atom db[110], int & size ) {

    ifstream ifile( pdbfilename );
    string ter = "TER";
    string blank = "";
    if ( !ifile.is_open() ) return false;

    size = 0;

    for ( int i = 0; i < 110; i = i + 1 ) {
      
      ifile >> db[size].atom_type ;
        if ( db[size].atom_type == ter ) {
	    continue;
        } 
        ifile        >> db[size].atom_number 
                     >> db[size].element 
                     >> db[size].type 
                     >> db[size].residue_number 
                     >> db[size].x_coord 
                     >> db[size].y_coord 
                     >> db[size].z_coord 
                     >> db[size].ligand_distance 
	             >> db[size].score;
	     size++;  
        
    }
    return true;
}

Pdb::Atom pdb[110];
int Pdb::number_of_atoms;
string Pdb::pdbfilename;
