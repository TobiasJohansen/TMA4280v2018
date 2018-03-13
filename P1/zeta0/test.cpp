#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include "riemann.h"

int main(int argc, char* argv[]) {
  if(argc != 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  printf("Serial approximation of pi using the Riemann Zeta function after %d iterations: %.17f\n\n", iterations, Riemann::pi_approximation(iterations));
  return 0;
}
