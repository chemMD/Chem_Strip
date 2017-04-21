/**
 * @short   PDB Header
 * @file    pdb.h
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This header file contains the structs Atom and Box. It carries the read_pdb,
 * the check_pdb and the write_pdb declarations.
 */

#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

// Properties of the atoms within the PDB file
struct Atom {
    string atom_type;
    int atom_number;
    string element;
    string type;
    int residue_number;
    double x_coord;
    double y_coord;
    double z_coord;
    double ligand_distance;
    double score;
};

//all of the variables that are shared within main and defined based on the PDB file
struct Box {
    vector<Atom> pdb;//all of the properties for every atom
    vector<int> strip_index;//index of every atom to be removed
    int number_of_atoms;//total number of atoms
    vector<int> rdf_solute_index;//index of every solute to be used in rdf calculation
    vector<int> rdf_solvent_index;//index of every solvent atom to be used in rdf calculation
    int rdf_solute_it;//number of solute atoms
    int rdf_solvent_it;//number of solvent atoms
};

bool read_pdb ( string pdbfilename, int & size, vector<Atom> & pdb, ofstream& log_file );

bool check_pdb ( string rdf_solute, string rdf_solute_atom,
        string rdf_solvent, string rdf_solvent_atom, vector<Atom> & pdb,
        vector<int> & rdf_solute_index, int & rdf_solute_it,
        vector<int> & rdf_solvent_index, int & rdf_solvent_it, ofstream& log_file);

bool write_pdb ( string pdboutname, string stripcommand,
        vector<Atom> & pdb, vector<int> & strip, ofstream& log_file );
