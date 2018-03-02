#include <fstream>
#include <iostream>
#include <math.h>
#include "machin.h"

int main(int argc, char* argv[]) {
  if(argc != 1) return 1;
  std::ofstream file("mach0/vtest.txt");
  for(double i = 1.0; i < 25.0; i++){
    file << "Difference between PI and PI approximated by Machin formula after 2^" << i << " iterations: " << fabs(M_PI - Machin::pi_approximation(pow(2, i))) << std::endl;
  }
  std::cout << "Results from serial Machin vtest saved to mach0/vtest.txt" << std::endl;
  file.close();
  return 0;
}
