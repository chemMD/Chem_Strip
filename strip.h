// simple multi file example with Car.h,  Car.cpp, and main.cpp
class strip {

 public:
  string get_residue () { return residue; }
  void set_residue (string newresidue);

 private:
  string   residue;
  string   atom;
  string   atomlist;
  string   distance;
};
