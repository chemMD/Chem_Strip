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

/**
 * @short   Main program
 * @file    main.cpp
 * @author  Caleb Gallops and Dennis Kennetz
 * @param   none
 * @return  0 on success
 */

int main( int argc, char* argv[] ) {

    cout << endl << "Initializing main..." << endl << endl;
    ofstream log_file;

    Input inp;

    //reads the user-specified parameters
    if ( !read_input( argv[1], inp, log_file ) ) {
        cout << "Problems opening input file: " << argv[1] << endl;
        return 0;
    }

    Box box;

    //reads the PDB file to identify all of the atoms in the box
    if ( !read_pdb( inp.pdbfilename, box.number_of_atoms, box.pdb, log_file ) ) {
        cout << "Problems opening pdb file: " << inp.pdbfilename << endl;
        return 0;
    }

    //checks the PDB file to see if any of the solute or solvent atoms are present
    if ( !check_pdb( inp.rdf_solute, inp.rdf_solute_atom, inp.rdf_solvent,
            inp.rdf_solvent_atom, box.pdb, box.rdf_solute_index, box.rdf_solute_it,
            box.rdf_solvent_index, box.rdf_solvent_it, log_file ) ) {
        cout << "Problems writing pdb file: " << inp.pdbfilename << endl;
        return 0;
    }

    //writes a copy of the PDB file without the atoms specified by the user
    if ( !write_pdb( inp.pdboutname, inp.stripcommand, box.pdb, box.strip_index, log_file ) ) {
        cout << "Problems writing pdb file: " << inp.pdbfilename << endl;
        return 0;
    }

    Trajectory traj;

    //reads the MDCRD file and saves the coordinates and periodic boundary conditions into vectors
    if ( !read_mdcrd( inp.mdcrdfilename, inp.time_steps,
            box.number_of_atoms, traj.mdcrd, traj.per_box_bound, log_file ) ) {
        cout << "Problems opening mdcrd file: " << inp.mdcrdfilename << endl;
        return 0;
    }

    //checks and saves the solute and solvent coordinates into vectors
    if ( !check_mdcrd( inp.mdcrdfilename, inp.time_steps,
            box.number_of_atoms,box.rdf_solute_index, box.rdf_solvent_index,
            traj.mdcrd, traj.rdf_solute_coord, traj.rdf_solvent_coord, log_file ) ) {
        cout << "Problems opening mdcrd file: " << inp.mdcrdfilename << endl;
        return 0;
    }

    //writes a copy of MDCRD file without the coordinates of the user-specified atoms
    if ( !write_mdcrd( inp.mdcrdoutname, inp.time_steps,
            box.number_of_atoms, box.strip_index, traj.mdcrd, traj.per_box_bound, log_file ) ) {
            cout << "Problems writing mdcrd file: " << inp.pdbfilename << endl;
            return 0;
    }

    cout << "MD_strip run is complete!" << endl << endl;
    return 0;
}
