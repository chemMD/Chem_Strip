/**
 * @mainpage The Gaussian Optimization Analytical Tool (GOAT)
 *
 * Welcome to the Gaussian Optimization Analytical Tool (GOAT) documentation site!
 * Users may find relevant info related to this program, a program designed to provide
 * structural analyses of biomolecules successfully optimized using Gaussian software.
 *
 * @short   Main program
 * @file    main.cpp
 * @author  Kate Charbonnet, Hannah Lozano, and Thomas Summers
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to remove any specified residue from any pdb, topology or trajectory
 * file and determine radial distribution between any two specified atoms. It requires only a command
 * script and, at least a pdb file.
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
#include "mdcrd.h"
int main() {

    Input inp;

    cout << "Initializing main..." << endl;

    if ( !inp.read_input( inp.inputfilename ) ) {
        cout << "Problems opening input file: " << inp.inputfilename << endl;
        return 0;
    }

    cout << inp.pdbfilename << endl;
    cout << inp.pdboutname << endl;
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
	     << setw(7) << left << p.pdb[i].type
	     << setw(8) << left << p.pdb[i].residue_number
	     << setw(8) << left << p.pdb[i].x_coord
	     << setw(8) << left << p.pdb[i].y_coord
	     << setw(8) << right << p.pdb[i].z_coord
	     << setw(6) << right << p.pdb[i].ligand_distance
	     << setw(6) << right << p.pdb[i].score
	     << endl;

    }

    cout << p.number_of_atoms << endl;
    
    if ( !p.write_pdb( inp.pdboutname, inp.stripcommand, p.pdb, p.number_of_atoms ) ) {
        cout << "Problems writing pdb file: " << p.pdbfilename << endl;
        return 0;
    }

    Mdcrd m;

    if ( !m.read_mdcrd( inp.mdcrdfilename, m.mdcrd, p.number_of_atoms ) ) {
      cout << "Problems opening mdcrd file: " << m.mdcrdfilename << endl;
      return 0;
    }

    return 0;   
}
   
