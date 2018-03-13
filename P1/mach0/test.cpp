#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include "machin.h"

int main(int argc, char* argv[]) {
  if(argc != 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  printf("Serial approximation of pi using the Machin formula after %d iterations: %.17f\n\n", iterations, Machin::pi_approximation(iterations));
  return 0;
}
