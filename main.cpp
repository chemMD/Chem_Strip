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

int main () {
    strip p;
    strip::Atom pdb[1000];
    int number_of_atoms;

    string   inputfilename;
    cout << "Executing main..." << endl;

    // input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
    if ( !p.read_input(inputfilename, pdb, number_of_atoms ) ) {
        cout << "Problems opening database file: " << inputfilename << endl;
        return 0;
    }

    cout << "Information about : " << number_of_atoms << " was read" << endl;
    cout << "Atom     #   Ele   Res    Seq       X       Y          Z       LD    Score" << endl;
    
    for (int i = 0; i < number_of_atoms; i++) {

        cout << setw(9) << left << pdb[i].atom_type 
	     << setw(4) << left << pdb[i].atom_number
	     << setw(6) << left << pdb[i].element
	     << setw(7) << left << p.Residue_Type_to_string(pdb[i].type) 
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
