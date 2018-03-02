#include <cstdlib>
#include <iostream>
#include "riemann.h"

int main(int argc, char* argv[]) {
  if(argc != 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  std::cout << "Approximation of pi using the Riemann Zeta function after " << iterations << " iterations: " << Riemann::pi_approximation(iterations) << std::endl;
  return 0;
}
