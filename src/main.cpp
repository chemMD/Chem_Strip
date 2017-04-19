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

    cout << "Initializing main..." << endl;

    Input input;
    Input* inp = &input;

    Box box;

    if ( !read_input( argv[1], inp ) ) {
        cout << "Problems opening input file: " << argv[1] << endl;
        return 0;
    }

    cout << inp->pdbfilename << endl;
    cout << inp->pdboutname << endl;
    cout << inp->mdcrdfilename << endl;
    cout << inp->mdcrdoutname << endl;
    cout << inp->stripcommand << endl;
    cout << inp->rdf_solute << endl;
    cout << inp->rdf_solute_atom << endl;
    cout << inp->rdf_solvent << endl;
    cout << inp->rdf_solvent_atom << endl;

    if ( !read_pdb( inp->pdbfilename, box.number_of_atoms, box.pdb) ) {

            cout << "Problems opening pdb file: " << inp->pdbfilename << endl;
        return 0;
    }

    cout << "Number of atoms: " << box.number_of_atoms << endl;

    if ( !check_pdb( inp->rdf_solute, inp->rdf_solute_atom, inp->rdf_solvent,
            inp->rdf_solvent_atom, box.pdb, box.rdf_solute_index,
            box.rdf_solute_it, box.rdf_solvent_index, box.rdf_solvent_it ) ) {

        cout << "Problems writing pdb file: " << inp->pdbfilename << endl;
        return 0;
    }

    cout << box.rdf_solute_it << endl;
    cout << box.rdf_solvent_it << endl;

    if ( !write_pdb( inp->pdboutname, inp->stripcommand, box.pdb, box.strip_index ) ) {

            cout << "Problems writing pdb file: " << inp->pdbfilename << endl;
        return 0;
    }

    Trajectory traj;

    cout << box.number_of_atoms << endl;

    if ( !read_mdcrd( inp->mdcrdfilename, inp->time_steps,
            box.number_of_atoms, traj.mdcrd, traj.per_box_bound ) ) {

        cout << "Problems opening mdcrd file: " << inp->mdcrdfilename << endl;
        return 0;
    }

    if ( !check_mdcrd( inp->mdcrdfilename, inp->time_steps,
            box.number_of_atoms,box.rdf_solute_index, box.rdf_solvent_index,
            traj.mdcrd, traj.rdf_solute_coord, traj.rdf_solvent_coord ) ) {

        cout << "Problems opening mdcrd file: " << inp->mdcrdfilename << endl;
        return 0;
    }

    if ( !write_mdcrd( inp->mdcrdoutname, inp->time_steps,
            box.number_of_atoms, box.strip_index, traj.mdcrd, traj.per_box_bound ) ) {

            cout << "Problems writing mdcrd file: " << inp->pdbfilename << endl;
            return 0;
    }

    return 0;
}
