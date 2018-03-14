OMP_NUM_THREADS=4

all:
	g++ zeta0/test.cpp -o zeta0/test.o
	g++ mach0/test.cpp -o mach0/test.o
	mpiCC zeta1/mpi.cpp -o zeta1/mpi.o
	mpiCC mach1/mpi.cpp -o mach1/mpi.o
	g++ zeta0/utest.cpp -o zeta0/utest.o
	g++ mach0/utest.cpp -o mach0/utest.o
	g++ zeta0/vtest.cpp -o zeta0/vtest.o
	g++ mach0/vtest.cpp -o mach0/vtest.o
	mpiCC reduc/machinAllreduce.cpp -o reduc/machinAllreduce.o
	mpiCC reduc/riemannRDS.cpp -o reduc/riemannRDS.o
	mpiCC reduc/riemannAllreduce.cpp -o reduc/riemannAllreduce.o
	mpiCC reduc/machinRDS.cpp -o reduc/machinRDS.o
	mpiCC -fopenmp zeta2/mpi.cpp -o zeta2/mpi.o
	mpiCC -fopenmp mach2/mpi.cpp -o mach2/mpi.o

test:
	zeta0/test.o 100000
	mach0/test.o 100000
	mpirun -n 2 zeta1/mpi.o 10
	mpirun -n 4 zeta1/mpi.o 10
	mpirun -n 8 zeta1/mpi.o 10
	mpirun -n 2 zeta1/mpi.o 1000
	mpirun -n 4 zeta1/mpi.o 1000
	mpirun -n 8 zeta1/mpi.o 1000
	mpirun -n 2 zeta1/mpi.o 100000
	mpirun -n 4 zeta1/mpi.o 100000
	mpirun -n 8 zeta1/mpi.o 100000
	mpirun -n 2 mach1/mpi.o 10
	mpirun -n 4 mach1/mpi.o 10
	mpirun -n 8 mach1/mpi.o 10
	mpirun -n 2 mach1/mpi.o 1000
	mpirun -n 4 mach1/mpi.o 1000
	mpirun -n 8 mach1/mpi.o 1000
	mpirun -n 2 mach1/mpi.o 100000
	mpirun -n 4 mach1/mpi.o 100000
	mpirun -n 8 mach1/mpi.o 100000
	mpirun -n 2 zeta2/mpi.o 10
	mpirun -n 4 zeta2/mpi.o 10
	mpirun -n 8 zeta2/mpi.o 10
	mpirun -n 2 zeta2/mpi.o 1000
	mpirun -n 4 zeta2/mpi.o 1000
	mpirun -n 8 zeta2/mpi.o 1000
	mpirun -n 2 zeta2/mpi.o 100000
	mpirun -n 4 zeta2/mpi.o 100000
	mpirun -n 8 zeta2/mpi.o 100000
	mpirun -n 2 mach2/mpi.o 10
	mpirun -n 4 mach2/mpi.o 10
	mpirun -n 8 mach2/mpi.o 10
	mpirun -n 2 mach2/mpi.o 1000
	mpirun -n 4 mach2/mpi.o 1000
	mpirun -n 8 mach2/mpi.o 1000
	mpirun -n 2 mach2/mpi.o 100000
	mpirun -n 4 mach2/mpi.o 100000
	mpirun -n 8 mach2/mpi.o 100000

utest:
	zeta0/utest.o
	mach0/utest.o

vtest:
	zeta0/vtest.o
	mach0/vtest.o

clean:
	rm -f */*.o */*.txt
