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
bool read_mdcrd (string mdcrdfilename,int time_steps, int number_of_atoms );
bool write_mdcrd (string mdcrdoutname );

