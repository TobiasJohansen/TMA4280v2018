test:
	g++ zeta0/test.cpp -o zeta0/test
	g++ mach0/test.cpp -o mach0/test
	mpiCC zeta1/mpi.cpp -o zeta1/mpi
	mpiCC mach1/mpi.cpp -o mach1/mpi
	zeta0/test 100
	mach0/test 100
	mpirun -n 2 zeta1/mpi 100
	mpirun -n 8 zeta1/mpi 100
	mpirun -n 16 zeta1/mpi 100
	mpirun -n 2 zeta1/mpi 1000
	mpirun -n 8 zeta1/mpi 1000
	mpirun -n 16 zeta1/mpi 1000
	mpirun -n 2 zeta1/mpi 10000
	mpirun -n 8 zeta1/mpi 10000
	mpirun -n 16 zeta1/mpi 10000
	mpirun -n 2 mach1/mpi 100
	mpirun -n 8 mach1/mpi 100
	mpirun -n 16 mach1/mpi 100
	mpirun -n 2 mach1/mpi 1000
	mpirun -n 8 mach1/mpi 1000
	mpirun -n 16 mach1/mpi 1000
	mpirun -n 2 mach1/mpi 10000
	mpirun -n 8 mach1/mpi 10000
	mpirun -n 16 mach1/mpi 10000


utest:
	g++ zeta0/utest.cpp -o zeta0/utest
	g++ mach0/utest.cpp -o mach0/utest
	zeta0/utest
	mach0/utest

vtest:
	g++ zeta0/vtest.cpp -o zeta0/vtest
	g++ mach0/vtest.cpp -o mach0/vtest
	zeta0/vtest
	mach0/vtest
