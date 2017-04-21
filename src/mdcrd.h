/**
 * @short   PDB Header
 * @file    pdb.h
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This header file contains the structs Coordinates and Trajectory. It also carries the
 * read_mdcrd, the check_mdcrd and the write_mdcrd declarations.
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

//Cartesion coordinates of the atoms within the MDCRD file
struct Coordinates {

    double X;
    double Y;
    double Z;
};

//all of the variables that are shared within main and defined based on the MDCRD file
struct Trajectory{

    vector<Coordinates> mdcrd;//coordinates of all of the atoms
    vector<Coordinates> per_box_bound;//dimensions of the periodic box
    vector<Coordinates> rdf_solute_coord;//coordinates of the solute atoms
    vector<Coordinates> rdf_solvent_coord;//coordinates of the solvent atoms

};

bool read_mdcrd (string mdcrdfilename,int time_steps, int number_of_atoms,
         vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound, ofstream& log_file );

bool check_mdcrd ( string mdcrdoutname, int time_steps,
        int number_of_atoms, vector<int> & rdf_solute_index,
        vector<int> & rdf_solvent_index, vector<Coordinates> & mdcrd,
        vector<Coordinates> & rdf_solute_coord,
        vector<Coordinates> & rdf_solvent_coord, ofstream& log_file );

bool write_mdcrd (string mdcrdoutname, int time_steps, int number_of_atoms,
         vector<int> & strip, vector<Coordinates> & mdcrd,
         vector<Coordinates> & per_box_bound, ofstream& log_file );
