// simple multi file example with Car.h,  Car.cpp, and main.cpp
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

class Pdb {

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
        static int number_of_atoms;
        Atom pdb[1000];
        Residue_Type string_to_Residue_Type (string s);
	string Residue_Type_to_string (Residue_Type c);
        static string pdbfilename;
        bool read_pdb (string pdbfilename, Atom db[1000], int & size);
        
    private:  
        string uppercase (string & s);
        bool is_valid_residue_type (string s);
};
