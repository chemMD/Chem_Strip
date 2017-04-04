#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

class Mdcrd {
    public:
        struct Coordinates {
            string X;
            string Y;
            string Z;
        };
        static int number_of_coordinates;
        Coordinates mdcrd[5272];
        static string mdcrdfilename;
        static string mdcrdoutname;
        bool read_mdcrd (string mdcrdfilename, Coordinates mdcrd[5272], int & size);
        //bool write_mdcrd (string mdcrdoutname, string stripcommand, Atom pdb[5272], int number_of_atoms);
};
