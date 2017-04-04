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
        Atom pdb[10000];
        static string pdbfilename;
        static string pdboutname;
        static string stripcommand;
        bool read_pdb (string pdbfilename, Atom pdb[10000], int & size);
        bool write_pdb (string pdboutename, string stripcommand, Atom pdb[10000], int number_of_atoms);
};
