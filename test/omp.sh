g++ -fopenmp test_omp.cpp -o omp_exe -lm
OMP_NUM_THREADS=2 ./omp_exe
rm omp_exe