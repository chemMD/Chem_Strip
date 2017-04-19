#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

struct Coordinates {
    double X;
    double Y;
    double Z;
};
struct Trajectory{
    vector<Coordinates> mdcrd;
    vector<Coordinates> per_box_bound;
    vector<Coordinates> rdf_solute_coord;
    vector<Coordinates> rdf_solvent_coord;

};

bool check_mdcrd ( string mdcrdoutname, int time_steps,
        int number_of_atoms, vector<int> & rdf_solute_index,
        vector<int> & rdf_solvent_index, vector<Coordinates> & mdcrd,
        vector<Coordinates> & rdf_solute_coord, vector<Coordinates> & rdf_solvent_coord );

bool read_mdcrd (string mdcrdfilename,int time_steps, int number_of_atoms,
         vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound );
bool write_mdcrd (string mdcrdoutname, int time_steps, int number_of_atoms,
         vector<int> & strip, vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound);
