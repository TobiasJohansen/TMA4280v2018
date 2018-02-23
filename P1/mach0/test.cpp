#include <cstdlib>
#include <iostream>
#include "machin.h"

int main(int argc, char* argv[]) {
  if(argc != 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  std::cout << "Approximation of pi using the Machin formula: " << Machin::pi_approximation(iterations) << std::endl;
  return 0;
}
