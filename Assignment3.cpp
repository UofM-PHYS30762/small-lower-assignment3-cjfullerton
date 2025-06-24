#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>


// This program creates a class called galaxy that takes data: name, hubble type, redshift, total mass,
// stellar mass fraction, satellites. Satellites are added to galaxies that have satellites and their values
// also printed.

// crete galaxy class
class galaxy
{
private:
  std::string name;
  std::string hubble_type;
  double redshift;
  double total_mass;
  double stellar_mass_fraction;
  std::vector<galaxy> satellites;

public:
  // Default constructor
  galaxy() : name{""}, hubble_type{""}, redshift{0}, total_mass{0}, stellar_mass_fraction{0}  {}

  // Parameterized constructor
  galaxy(std::string name, std::string hubble_type, double redshift, double total_mass, double stellar_mass_fraction) :
    name{name}, hubble_type{hubble_type}, redshift{redshift}, total_mass{total_mass}, stellar_mass_fraction{stellar_mass_fraction} 
  {}

  // Destructor
  ~galaxy() 
  {
    std::cout<<"Destroying "<<name<<std::endl;
  }

  double stellar_mass() // member function
  {
    return total_mass * stellar_mass_fraction;
  }

 void print_data() // memeber function
 {
    std::cout<<"Galaxy: [name, hubble type, redshift, total mass, stellar mass fraction, stellar mass] = ["<<name<<","<<hubble_type<<","<< redshift
	   <<","<<total_mass<<","<<stellar_mass_fraction<<","<<stellar_mass()<<"]"<<std::endl;
    for(auto satellite_it=satellites.begin(); satellite_it<satellites.end(); ++satellite_it){
      std::cout<<"\tSatellite: ";
      satellite_it->print_data();
    }
  }

  // member function to add satellite
  void add_satellite(std::string name, std::string hubble_type, double redshift, double total_mass, double stellar_mass_fraction) {
    satellites.push_back(galaxy(name, hubble_type, redshift, total_mass, stellar_mass_fraction));
  }



};

int main()
{
  galaxy Milky_Way("Milky Way", "Sc", 0, 1.15e12, 0.03);
  galaxy Andromeda("Andromeda", "Sb", -0.001004, 1.23e12, 0.05);

  Milky_Way.add_satellite(std::string("LMC"), std::string("Irr"), 0.0003, 3.6e9, 0.05);
  Milky_Way.add_satellite(std::string("SMC"), std::string("SBm"), 0.0005, 2.7e9, 0.04);

  Milky_Way.print_data();
  Andromeda.print_data();

  return 0;
}
