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
    cout << i.mdcrdoutname << endl;
    cout << i.stripcommand << endl;
    cout << i.rdfcommand << endl;

    if ( !read_pdb( i.pdbfilename, number_of_atoms) ) {
        cout << "Problems opening pdb file: " << i.pdbfilename << endl;
        return 0;
    }

    cout << "Number of atoms: " << number_of_atoms << endl;

    if ( !write_pdb( i.pdboutname, i.stripcommand ) ) {
        cout << "Problems writing pdb file: " << i.pdbfilename << endl;
        return 0;
    }
    cout << number_of_atoms << endl;
    if ( !read_mdcrd( i.mdcrdfilename, i.time_steps, number_of_atoms ) ) {
        cout << "Problems opening mdcrd file: " << i.mdcrdfilename << endl;
        return 0;
    }
    if ( !write_mdcrd( i.mdcrdoutname, i.time_steps, number_of_atoms) ) {
            cout << "Problems writing mdcrd file: " << i.pdbfilename << endl;
            return 0;
        }
    return 0;
}
