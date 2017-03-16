// simple multi file example with Car.h,  Car.cpp, and main.cpp
#include <string>

using namespace std;

class strip {

 public:
  string get_residue () { return residue; }
  void set_residue (string resname);
  //  string get_pdb () { return pdb; }
  //void set_pdb (string pdb_name);
  //string get_traj () { return traj; }
  //void set_traj (string traj_name );
  //string get_parm () { return parm; }
  //void set_parm ( string parm_name );

 private:
  string   residue;
  string   atom;
  string   atomlist;
  string   distance;
  string   resname;
};
