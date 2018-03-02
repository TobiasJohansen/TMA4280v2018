#include <fstream>
#include <math.h>
#include "riemann.h"

int main(int argc, char* argv[]) {
  if(argc != 1) return 1;
  std::ofstream file("zeta0/vtest.txt");
  for(double i = 1.0; i < 25.0; i++){
    file << "Difference between PI and PI approximated by Riemann Zeta function after 2^" << i << " iterations is: " << fabs(M_PI - Riemann::pi_approximation(pow(2, i))) << std::endl;
  }
  file.close();
  return 0;
}
