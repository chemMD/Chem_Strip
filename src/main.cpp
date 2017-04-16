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

    Input input;
    Input* inp = &input;

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

    int number_of_atoms;

    vector<Atom> pdb;
    vector<int> strip_index;

    vector<int> rdf_solute;
    vector<int> rdf_solvent;
    vector<int> rdf_solute_index;
    vector<int> rdf_solvent_index;

    if ( !read_pdb( inp->pdbfilename, number_of_atoms, pdb) ) {
        cout << "Problems opening pdb file: " << inp->pdbfilename << endl;
        return 0;
    }
    cout << "Number of atoms: " << number_of_atoms << endl;

    if ( !check_pdb( inp->rdf_solute, inp->rdf_solute_atom, inp->rdf_solvent,
        inp->rdf_solvent_atom, pdb, rdf_solute_index, rdf_solvent_index ) ) {
        cout << "Problems writing pdb file: " << inp->pdbfilename << endl;
        return 0;
    }

    if ( !write_pdb( inp->pdboutname, inp->stripcommand, pdb, strip_index ) ) {
        cout << "Problems writing pdb file: " << inp->pdbfilename << endl;
        return 0;
    }

    cout << number_of_atoms << endl;

    vector<Coordinates> mdcrd;
    vector<Coordinates> per_box_bound;
    vector<Coordinates> rdf_solute_coord;
    vector<Coordinates> rdf_solvent_coord;

    if ( !read_mdcrd( inp->mdcrdfilename, inp->time_steps,
            number_of_atoms, mdcrd, per_box_bound ) ) {
        cout << "Problems opening mdcrd file: " << inp->mdcrdfilename << endl;
        return 0;
    }

    if ( !check_mdcrd( inp->mdcrdfilename, inp->time_steps,number_of_atoms,
           rdf_solute_index, rdf_solvent_index, mdcrd, rdf_solute_coord, rdf_solvent_coord ) ) {
        cout << "Problems opening mdcrd file: " << inp->mdcrdfilename << endl;
        return 0;
    }

    if ( !write_mdcrd( inp->mdcrdoutname, inp->time_steps,
            number_of_atoms, strip_index, mdcrd, per_box_bound ) ) {
            cout << "Problems writing mdcrd file: " << inp->pdbfilename << endl;
            return 0;
    }

    return 0;
}
