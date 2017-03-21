/**
 * @mainpage Chemistry_Strip Program
 *
 * Welcome to the Chemistry_Strip documentation. Here you will find all the relevant info
 * related to this program which was designed to remove residues from AMBER suite 
 * trajectory and topology files.
 */
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

/**
 * @short   Chemistry_Strip
 * @file    strip.cpp
 * @author  Caleb Gallops & Dennis Kennetz
 * @param   none
 * @return  0 on success
 *
 * This program removes any specified residue from AMBER suite trajectory and topology files 
 * It also simultaneously produces radial distribution functions for the removed residue.
 * This is intended to reduce the size of these files so quicker analyses can be performed.  
 * The purpose of producing an radial distribution is to extract any valuable information 
 * before the strip. 
 */

using namespace std;

#include "strip.h"

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

const int MAXSIZE = 1000;

string uppercase (string & s) {
    string result = s;
    for (int i=0; i < (int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
}

bool is_valid_residue_type (string s) {
    string ss = uppercase(s);
    return ( (ss=="WAT") || (ss=="AMG") || (ss=="CL") || (ss=="CUB") );
}

string Residue_Type_to_string (Residue_Type c) {
    switch (c) {
    case WAT: return "WAT";
    case AMG: return "AMG";
    case Cl:   return "Cl";
    case CUB: return "CUB";
    }

  // It should never get here!!                                                     
    exit(EXIT_FAILURE);

}

Residue_Type string_to_Residue_Type (string s) {

    string ss = uppercase(s);

    if (ss == "WAT") return WAT;
    if (ss == "AMG") return AMG;
    if (ss == "CL"  ) return Cl;
    if (ss == "CUB") return CUB;

  // It should never get here!!                                                     
    exit(EXIT_FAILURE);
}

bool read_input (string inputfilename, Atom db[MAXSIZE], int & size) {

    ifstream ifile(inputfilename.c_str());
    if ( !ifile.is_open() ) return false;             
    
    string type;

    size = 0;

    while ( size < MAXSIZE ) {

        if ( !(ifile >> db[size].atom_type >> db[size].atom_number 
            >> db[size].element >> type >> db[size].residue_number
            >> db[size].x_coord >> db[size].y_coord >> db[size].z_coord 
            >> db[size].ligand_distance >> db[size].score ) )
            break;

        if ( !is_valid_residue_type(type) ) {
            cout << "Invalid residue type: " << type
                 << "; assuming WAT" << endl;
            type = "WAT";
        }

        db[size].type = string_to_Residue_Type(type);
        size++;
    }
    return true;
}

int main () {
    
    Atom pdb[MAXSIZE];
    int number_of_atoms;

    string   inputfilename;
    cout << "Executing main..." << endl;

    // input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
     
    if ( !read_input(inputfilename, pdb, number_of_atoms ) ) {
        cout << "Problems opening database file: " << inputfilename << endl;
        return 0;
    }

    cout << "Information about : " << number_of_atoms << " was read" << endl;
    cout << "Atom     #   Ele   Res    Seq       X       Y          Z       LD    Score" << endl;
    
    for (int i = 0; i < number_of_atoms; i++) {

        cout << setw(9) << left << pdb[i].atom_type 
	     << setw(4) << left << pdb[i].atom_number
	     << setw(6) << left << pdb[i].element
	     << setw(7) << left << Residue_Type_to_string(pdb[i].type) 
	     << setw(8) << left << pdb[i].residue_number
	     << setw(8) << left << pdb[i].x_coord
             << setw(8) << left << pdb[i].y_coord
             << setw(8) << right << pdb[i].z_coord
	     << setw(6) << right << pdb[i].ligand_distance
             << setw(6) << right << pdb[i].score
             << endl;
    }    
        
    return 0;
}
