#include "molecule.h"

/**
 * This function allows for molecule selection within the trajectory
 */

void mol_selection (int& type_mol_1, int& type_mol_2, int& apm_mol_1, int& apm_\
mol_2, vector<double>& m1, vector<double>& m2, double& totm1, double& totm2)
{

  if (type_mol_1 == 1) // Type copper
  {
    apm_mol_1 = 3;
    m1.push_back(63.546); // copper molecular weight
    totm1 = m1[0];
  }
  else if (type_mol_1 == 2) // Type h2o
  {
    apm_mol_1 = 3;
    m1.push_back(15.999); // oxygen molecular weight
    m1.push_back(1.008);  // hydrogen molecular weight
    m1.push_back(1.008);  // hydrogen molecular weight
    totm1 = m1[0] + m1[1] + m1[2];
  }
  else if (type_mol_1 == 3) // Type nh3
  {
    apm_mol_1 = 3;
    m1.push_back(14.007); // nitrogen molecular weight
    m1.push_back(1.008);  // hydrogen molecular weight
    m1.push_back(1.008);  // hydrogen molecular weight
    m1.push_back(1.008);  // hydrogen molecular weight
    totm1 = m1[0] + m1[1] + m1[2] + m1[3];
  }
  else
    {
      cerr << "Error in selection of molecule type: pick a different molecule!"\
 << endl;
    }

  if (type_mol_2 == 1) // Type copper
  {
    apm_mol_2 = 3;
    m2.push_back(63.546); // copper molecular weight
    totm2 = m2[0];
  }
  else if (type_mol_2 == 2) // Type h2o
  {
    apm_mol_2 = 3;
    m2.push_back(15.999); // oxygen molecular weight
    m2.push_back(1.008);  // hydrogen molecular weight
    m2.push_back(1.008);  // hydrogen molecular weight
    totm2 = m2[0] + m2[1] + m2[2];
  }
  else if (type_mol_2 == 3) // Type nh3
  {
    apm_mol_2 = 3;
    m2.push_back(14.007); // nitrogen molecular weight
    m2.push_back(1.008);  // hydrogen molecular weight
    m2.push_back(1.008);  // hydrogen molecular weight
    m2.push_back(1.008);  // hydrogen molecular weight
    totm2 = m2[0] + m2[1] + m2[2] + m2[3];
  }
  else
    {
      cerr << "Error in selection of molecule type: pick a different molecule!"\
 << endl;
    }
}
