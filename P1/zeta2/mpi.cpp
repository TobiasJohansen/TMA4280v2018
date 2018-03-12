#include "riemann.h"
#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int threads = 4;
  double sum = 0.0;
  int iterations = 10000000;
  #pragma omp parallel for num_threads(threads) schedule(guided, 1) reduction(+:sum)
  for (size_t i = iterations; i > 0; i--) {
    sum += Riemann::pi_approximation(i);
  }
  sum = sqrt(6*sum);
  printf("Parallel approximation of PI using the Riemann Zeta function after %d iterations, with %d threads: %.17f\n", iterations, threads, sum);
  printf("Difference between PI and PI approximated by Riemann Zeta function: %.17f\n", fabs(M_PI-sum));
  return 0;
}
