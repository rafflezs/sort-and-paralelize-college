mpic++ -std=c++17 mpi/test_bubble.cpp -o mpi_exe -lm
mpirun -n 2 ./mpi_exe
rm mpi_exe

mpic++ -std=c++17 mpi/test_merge.cpp -o mpi_exe -lm
mpirun -n 2 ./mpi_exe
rm mpi_exe

mpic++ -std=c++17 mpi/test_quick.cpp -o mpi_exe -lm
mpirun -n 2 ./mpi_exe
rm mpi_exe