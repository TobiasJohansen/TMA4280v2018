#include "machin.h"
#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int threads = 4;
  double sum = 0.0;
  int iterations = 10000000;
  #pragma omp parallel for num_threads(threads) schedule(guided, 1) reduction(+:sum)
  for (size_t i = iterations; i > 0; i--) {
    sum += 4*(4*Machin::arctan_approximation(i, 1.0/5)-Machin::arctan_approximation(i, 1.0/239));
  }
  printf("Parallel approximation of PI using the Machin formula after %d iterations, with %d threads: %.17f\n", iterations, threads, sum);
  printf("Difference between PI and PI approximated by Machin formula: %.17f\n", fabs(M_PI-sum));
  return 0;
}
