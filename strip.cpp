
#include <string>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

int main () {

    string   inputfilename;
    ifstream inputfile;
    string   residueinputname;
    string   atom;
    string   atomlist;
    
    // Prompt user for input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
    cout << "Enter name of residue to be removed:";
    cin  >> residueinputname;

    // Sanity check on the file stream
    inputfile.open(inputfilename.c_str());
    if ( !inputfile.is_open() ) {
        cout << "Cannot open input file: " 
             << inputfilename
             << endl;
        return 1;
    }
}



