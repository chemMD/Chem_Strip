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

    cout << inp.pdbfilename << endl;
    cout << inp.pdboutname << endl;
    cout << inp.mdcrdfilename << endl;
    cout << inp.mdcrdoutname << endl;
    cout << inp.stripcommand << endl;
    cout << inp.rdfcommand << endl;

    if ( !read_pdb( inp.pdbfilename, number_of_atoms) ) {
        cout << "Problems opening pdb file: " << inp.pdbfilename << endl;
        return 0;
    }

    cout << "Number of atoms: " << number_of_atoms << endl;

    if ( !write_pdb( inp.pdboutname, inp.stripcommand ) ) {
        cout << "Problems writing pdb file: " << inp.pdbfilename << endl;
        return 0;
    }

    cout << number_of_atoms << endl;

    if ( !read_mdcrd( inp.mdcrdfilename, inp.time_steps, number_of_atoms ) ) {
        cout << "Problems opening mdcrd file: " << inp.mdcrdfilename << endl;
        return 0;
    }

    if ( !write_mdcrd( inp.mdcrdoutname, inp.time_steps, number_of_atoms) ) {
            cout << "Problems writing mdcrd file: " << inp.pdbfilename << endl;
            return 0;
        }

    return 0;
}
