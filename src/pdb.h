#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

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

bool read_pdb ( string pdbfilename, int & size, vector<Atom> & pdb );
bool check_pdb ( string rdf_solute, string rdf_solute_atom,
        string rdf_solvent, string rdf_solvent_atom, vector<Atom> & pdb,
        vector<int> & rdf_solute_index, int & rdf_solute_it,
        vector<int> & rdf_solvent_index, int & rdf_solvent_it);
bool write_pdb ( string pdboutname, string stripcommand, vector<Atom> & pdb, vector<int> & strip );
