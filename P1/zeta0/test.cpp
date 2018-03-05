#include <cstdlib>
#include <iostream>
#include "riemann.h"


#include <iomanip>

int main(int argc, char* argv[]) {
  if(argc != 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  std::cout << "Serial approximation of pi using the Riemann Zeta function after " << iterations << " iterations: " << std::setprecision(60) << Riemann::pi_approximation(iterations) << "\n" << std::endl;
  return 0;
}
