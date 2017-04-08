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

extern vector<Coordinates> mdcrd;
//static string mdcrdoutname;
bool read_mdcrd (string mdcrdfilename, int number_of_atoms );
//bool write_mdcrd (string mdcrdoutname, string stripcommand, Atom pdb[5272], int number_of_atoms);

