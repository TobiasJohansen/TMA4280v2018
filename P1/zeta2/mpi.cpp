#include <cstdlib>
#include <omp.h>
#include <stdio.h>
#include "riemann.h"

int main(int argc, char** argv) {
  if(argc < 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  double sum = 0.0;
  #pragma omp parallel for schedule(guided, 1) reduction(+:sum)
  for (int i = iterations; i > 0; i--) {
    sum += Riemann::pi_approximation(i);
  }
  sum = sqrt(6*sum);
  printf("Parallel approximation of PI using the Riemann Zeta function after %d iterations, with %d threads: %.17f\n", iterations, omp_get_max_threads(), sum);
  printf("Difference between PI and PI approximated by Riemann Zeta function: %.17f\n\n", fabs(M_PI-sum));
  return 0;
}
