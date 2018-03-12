#include <iostream>
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
    sum += 4*(4*Machin::arctan_approximation(i, 1.0/5)-Machin::arctan_approximation(i, 1.0/239));
  }
  printf("Sum of process %d: %.17f\n", world_rank, sum);
  //if(world_rank < rest){
    // Sums blocks
    //sum = Machin::pi_approximation(world_rank*iperprocs+world_rank+1,world_rank*iperprocs+world_rank+iperprocs+2);
    // Sums each processes*i

    //printf("[%d]-[%d] Sum of process %d: %.60f\n", world_rank*iperprocs+world_rank+1, world_rank*iperprocs+world_rank+iperprocs+1, world_rank, sum);
    //std::cout << "[" << world_rank*iperprocs+world_rank*1+1 << "] - [" << world_rank*iperprocs+world_rank*1+iperprocs+1 << "]\n"
    //<< "Sum of process " << world_rank << " is: " << sum << std::endl;
  //}else{
    //sum = Machin::pi_approximation(world_rank*iperprocs+rest+1,world_rank*iperprocs+rest+1+iperprocs);
    //printf("[%d]-[%d] Sum of process %d: %.60f\n", world_rank*iperprocs+rest+1, world_rank*iperprocs+rest+iperprocs, world_rank, sum);
    //std::cout << "[" << world_rank*iperprocs+rest+1 << "] - [" << world_rank*iperprocs+rest+iperprocs << "]\n"
    //<< "Sum of process " << world_rank << " is: " << sum << std::endl;
  //}
  fflush(stdout);
  double global_sum = 0;
  MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if(world_rank == 0){
    sleep(0.01);
    std::cout << "Parallel approximation of PI using the Machin formula after " << iterations << " iterations, with " << world_size
    << " processes: " << std::setprecision(17) << global_sum << "\n";
    std::cout << "Difference between PI and PI approximated by Machin formula: " << std::setprecision(17) << fabs(M_PI-global_sum) << "\n";
    std::cout << "Wall time: " << std::setprecision(3) << (MPI_Wtime() - wTime)*1000 << " ms.\n" << std::endl;
  }
  // Finalize the MPI environment.
  MPI_Finalize();
  return 0;
}
