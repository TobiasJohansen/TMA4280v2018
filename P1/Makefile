test:
	g++ zeta0/test.cpp -o zeta0/test.o
	g++ mach0/test.cpp -o mach0/test.o
	mpiCC zeta1/mpi.cpp -o zeta1/mpi.o
	mpiCC mach1/mpi.cpp -o mach1/mpi.o
	zeta0/test.o 100
	mach0/test.o 100
	mpirun -n 2 zeta1/mpi.o 100
	mpirun -n 8 zeta1/mpi.o 100
	mpirun -n 16 zeta1/mpi.o 100
	mpirun -n 2 zeta1/mpi.o 1000
	mpirun -n 8 zeta1/mpi.o 1000
	mpirun -n 16 zeta1/mpi.o 1000
	mpirun -n 2 zeta1/mpi.o 10000
	mpirun -n 8 zeta1/mpi.o 10000
	mpirun -n 16 zeta1/mpi.o 10000
	mpirun -n 2 mach1/mpi.o 100
	mpirun -n 8 mach1/mpi.o 100
	mpirun -n 16 mach1/mpi.o 100
	mpirun -n 2 mach1/mpi.o 1000
	mpirun -n 8 mach1/mpi.o 1000
	mpirun -n 16 mach1/mpi.o 1000
	mpirun -n 2 mach1/mpi.o 10000
	mpirun -n 8 mach1/mpi.o 10000
	mpirun -n 16 mach1/mpi.o 10000


utest:
	g++ zeta0/utest.cpp -o zeta0/utest.o
	g++ mach0/utest.cpp -o mach0/utest.o
	zeta0/utest.o
	mach0/utest.o

vtest:
	g++ zeta0/vtest.cpp -o zeta0/vtest.o
	g++ mach0/vtest.cpp -o mach0/vtest.o
	zeta0/vtest.o
	mach0/vtest.o
