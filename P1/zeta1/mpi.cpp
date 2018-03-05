#include <iostream>
#include <cmath>
#include <mpi.h>
#include "riemann.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iomanip>

int main(int argc, char** argv) {

  if(argc != 2) return 1;
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
  int iperprocs = iterations/world_size;
  int rest = iterations % world_size;
  double sum = 0;
  if(world_rank < rest){
    sum = Riemann::pi_approximation(world_rank*iperprocs+world_rank+1,world_rank*iperprocs+world_rank+iperprocs+2);
    //std::cout << "[" << world_rank*iperprocs+world_rank*1+1 << "] - [" << world_rank*iperprocs+world_rank*1+iperprocs+1 << "]\n"
    //<< "Sum of process " << world_rank << " is: " << sum << std::endl;
  }else{
    sum = Riemann::pi_approximation(world_rank*iperprocs+rest+1,world_rank*iperprocs+rest+1+iperprocs);
    //std::cout << "[" << world_rank*iperprocs+rest+1 << "] - [" << world_rank*iperprocs+rest+iperprocs << "]\n"
    //<< "Sum of process " << world_rank << " is: " << sum << std::endl;
  }
  double global_sum = 0;
  MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);
  if(world_rank == 0){
    std::cout << "Parallel approximation of pi using the Riemann Zeta function after " << iterations << " iterations, with " << world_size
    << " processes: " << std::setprecision(60) << sqrt(6*global_sum) << "\n";
    std::cout << "Difference between PI and PI approximated by Riemann Zeta function: " << std::setprecision(60) << fabs(M_PI-global_sum) << "\n";
    std::cout << "Wall time: " << std::setprecision(3) << "\n" << (MPI_Wtime() - wTime)*1000 << " ms.\n" << std::endl;
  }
  // Finalize the MPI environment.
  MPI_Finalize();
  return 0;
}
