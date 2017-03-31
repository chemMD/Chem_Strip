// simple multi file example with Car.h,  Car.cpp, and main.cpp
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

class Pdb {

    public:
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
        static int number_of_atoms;
        Atom pdb[1000];
        static string pdbfilename;
        bool read_pdb (string pdbfilename, Atom db[1000], int & size);
};
