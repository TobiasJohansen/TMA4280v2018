#include <iostream>
#include <cmath>
#include <mpi.h>
#include "riemann.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iomanip>

int main(int argc, char** argv) {

  if(argc < 2) return 1;
  int iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  if ((world_size & (world_size - 1)) != 0){
    if (world_rank == 0){
      std::cout << world_size << " is not a power of two." << std::endl;
    }
    return 1;
  }
  double wTime;
  if(world_rank == 0){
    wTime = MPI_Wtime();
  }
  double sum = 0;
  for(int i = iterations - world_rank; i > 0; i -= world_size){
    //printf("r:%d: i:%d\t",world_rank, i);
    sum += Riemann::pi_approximation(i);
  }
  printf("Sum of process %d: %.17f\n", world_rank, sum);
  fflush(stdout);
  int stop = log2(world_size);
  for(int d = 0; d < stop; d++){
    int q = world_rank xor (int) pow(2, d);
    MPI_Send(&sum, 1, MPI_DOUBLE, q, 0, MPI_COMM_WORLD);
    double r = 0;
    MPI_Recv(&r, 1, MPI_DOUBLE, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    sum += r;
  }
  if(world_rank == 0){
    sum = sqrt(6*sum);
    sleep(0.01);
    std::cout << "Parallel approximation of PI using the Riemann Zeta function after " << iterations << " iterations, with " << world_size
    << " processes: " << std::setprecision(17) << sum << "\n";
    std::cout << "Difference between PI and PI approximated by Riemann Zeta function: " << std::setprecision(17) << fabs(M_PI-sum) << "\n";
    std::cout << "Wall time: " << std::setprecision(3) << (MPI_Wtime() - wTime)*1000 << " ms.\n" << std::endl;
  }
  // Finalize the MPI environment.
  MPI_Finalize();
  return 0;
}
