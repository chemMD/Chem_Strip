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

string Pdb::uppercase ( string & s ) {
    string result = s;
    for ( int i=0; i < (int)result.size(); i++ )
        result[i] = toupper(result[i]);
    return result;
}

bool Pdb::is_valid_residue_type ( string s ) {
    string ss = uppercase(s);
    return ( (ss=="WAT") || (ss=="AMG") || (ss=="CL") || (ss=="CUB") );
}

string Pdb::Residue_Type_to_string ( Residue_Type c ) {
    switch (c) {
    case WAT: return "WAT";
    case AMG: return "AMG";
    case Cl:   return "Cl";
    case CUB: return "CUB";
    }

    exit(EXIT_FAILURE);

}

Pdb::Residue_Type Pdb::string_to_Residue_Type ( string s ) {

    string ss = uppercase(s);

    if (ss == "WAT") return WAT;
    if (ss == "AMG") return AMG;
    if (ss == "CL"  ) return Cl;
    if (ss == "CUB") return CUB;

    exit(EXIT_FAILURE);

}

bool Pdb::read_pdb ( string pdbfilename, Atom db[1000], int & size ) {

    ifstream ifile( pdbfilename );
    if ( !ifile.is_open() ) return false;

    string type;

    size = 0;

    while ( size < 1000 ) {

        if ( !(ifile >> db[size].atom_type >> db[size].atom_number >> db[size].element >> type >> db[size].residue_number >> db[size].x_coord >> db[size].y_coord >> db[size].z_coord >> db[size].ligand_distance >> db[size].score ) )
            break;

        if ( !is_valid_residue_type(type) ) {
	    cout << "Invalid residue type: " << type
	         << "; assuming WAT" << endl;
	    type = "WAT";
        }
        db[size].type = string_to_Residue_Type(type);
        size++;
        }
    return true;
}       

Pdb::Atom pdb[1000];

int Pdb::number_of_atoms;

string Pdb::pdbfilename;
 
