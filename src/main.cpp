/**
 * @mainpage The Molecular Dynamics File Strip (MD_strip)
 *
 * Welcome to The Molecular Dynamics File Strip (MD_strip) documentation site!
 * Users may find relevant info related to this program, a program designed to remove
 * residues from Protein Data Base (pdb) files and topology (mdcrd) files used in molecular dynamics.
 *
 * @short   Main program
 * @file    main.cpp
 * @author  Caleb Gallops and Dennis Kennetz
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

int main( int argc, char* argv[] ) {

    cout << "Initializing main..." << endl;
    if ( !read_input( argv[1] ) ) {
        cout << "Problems opening input file: " << argv[1] << endl;
        return 0;
    }

    cout << i.pdbfilename << endl;
    cout << i.pdboutname << endl;
    cout << i.mdcrdfilename << endl;
    cout << i.stripcommand << endl;
    cout << i.rdfcommand << endl;

    Pdb p;

    if ( !p.read_pdb( i.pdbfilename, p.pdb, p.number_of_atoms ) ) {
        cout << "Problems opening pdb file: " << p.pdbfilename << endl;
        return 0;
    }

    cout << "Number of atoms: " << p.number_of_atoms << endl;
    if ( !p.write_pdb( i.pdboutname, i.stripcommand, p.pdb, p.number_of_atoms ) ) {
        cout << "Problems writing pdb file: " << p.pdbfilename << endl;
        return 0;
    }

    Mdcrd m;

    if ( !m.read_mdcrd( i.mdcrdfilename, m.mdcrd, p.number_of_atoms ) ) {
        cout << "Problems opening mdcrd file: " << m.mdcrdfilename << endl;
        return 0;
    }

    return 0;
}
