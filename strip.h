// simple multi file example with Car.h,  Car.cpp, and main.cpp
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

class strip {

    public:
        enum Residue_Type {
            WAT,
            AMG,
            Cl,
            CUB,
        };
        struct Atom {
            string atom_type;
            int atom_number;
            string element;
            Residue_Type type;
            string residue_number;
            double x_coord;
            double y_coord;
            double z_coord;
            double ligand_distance;
            double score;
        };  
        string uppercase (string & s);
        bool is_valid_residue_type (string s);
        string Residue_Type_to_string (Residue_Type c);
        Residue_Type string_to_Residue_Type (string s);
	bool read_input (string inputfilename, Atom db[1000], int & size);
};
