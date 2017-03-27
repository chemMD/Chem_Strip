
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

int main() {

    Input inp;

    cout << "Initializing main..." << endl;

    if ( !inp.read_input( inp.inputfilename ) ) {
        cout << "Problems opening input file: " << inp.inputfilename << endl;
        return 0;
    }

    cout << inp.pdbfilename << endl;
    cout << inp.parmfilename << endl;
    cout << inp.mdcrdfilename << endl;
    cout << inp.stripcommand << endl;
    cout << inp.rdfcommand << endl; 

    Pdb p;

    if ( !p.read_pdb( inp.pdbfilename, p.pdb, p.number_of_atoms ) ) {
        cout << "Problems opening pdb file: " << p.pdbfilename << endl;
        return 0;
    }

    cout << "Information about : " << p.number_of_atoms << " was read" << endl;
    cout << "Atom     #   Ele   Res    Seq       X       Y          Z       LD \
   Score" << endl;

    for ( int i = 0; i < p.number_of_atoms; i++ ) {

        cout << setw(9) << left << p.pdb[i].atom_type
	     << setw(4) << left << p.pdb[i].atom_number
	     << setw(6) << left << p.pdb[i].element
	     << setw(7) << left << p.Residue_Type_to_string(p.pdb[i].type)
	     << setw(8) << left << p.pdb[i].residue_number
	     << setw(8) << left << p.pdb[i].x_coord
	     << setw(8) << left << p.pdb[i].y_coord
	     << setw(8) << right << p.pdb[i].z_coord
	     << setw(6) << right << p.pdb[i].ligand_distance
	     << setw(6) << right << p.pdb[i].score
	     << endl;
    }

    return 0;   
}
