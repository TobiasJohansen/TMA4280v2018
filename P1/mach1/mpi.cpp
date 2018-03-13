#include <cmath>
#include <mpi.h>
#include "machin.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iomanip>

int main(int argc, char** argv) {
  if(argc < 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  MPI_Init(&argc, &argv);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  if ((world_size & (world_size - 1)) != 0){
    if (world_rank == 0){
      printf("%d is not a power of two.", world_size);
    }
    return 1;
  }
  double wTime;
  if(world_rank == 0){
    wTime = MPI_Wtime();
  }
  double sum = 0;
  for(int i = iterations - world_rank; i > 0; i -= world_size){
    sum += 4*(4*Machin::arctan_approximation(i, 1.0/5)-Machin::arctan_approximation(i, 1.0/239));
  }
  printf("Sum of process %d: %.17f\n", world_rank, sum);
  fflush(stdout);
  double global_sum = 0;
  MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if(world_rank == 0){
    sleep(0.01);
    printf("Parallel approximation of PI using the Machin formula after %d iterations, with %d processes: %.17f\n", iterations, world_size, global_sum);
    printf("Difference between PI and PI approximated by Machin formula: %.17f\n", fabs(M_PI-global_sum));
    printf("Wall time: %.3f ms.\n\n", (MPI_Wtime() - wTime)*1000);
  }
  MPI_Finalize();
  return 0;
}
