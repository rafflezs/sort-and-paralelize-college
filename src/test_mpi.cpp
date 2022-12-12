#include "./public/includes.hpp"
#include "../mpi/bubble.hpp"

#include "../mpi/merge.hpp"

#include "../mpi/quick.hpp"

int main(int argc, char **argv)
{

    double start, stop;

    // auto gen = new UnsortedGenerator();
    // gen->generate_file(1000, 0, 1000, 0);
    // delete gen;


    // //OpenMPI
    // start = clock();
    // auto bmpi = new BubbleMPI();
    // bmpi->sort(argc, argv);
    // delete bmpi;
    // stop = clock();
    // printf("Bubble MPI - Tempo gasto: %.2f\n\n", (stop - start) / CLOCKS_PER_SEC);

    // start = clock();
    // auto mmpi = new MergeMPI();
    // mmpi->sort(argc, argv);
    // delete mmpi;
    // stop = clock();
    // printf("Merge MPI - Tempo gasto: %.2f\n\n", (stop - start) / CLOCKS_PER_SEC);

    // start = clock();
    // auto qmpi = new QuickMPI();
    // qmpi->sort(argc, argv);
    // delete qmpi;
    // stop = clock();
    // printf("Quick MPI - Tempo gasto: %.2f\n\n", (stop - start) / CLOCKS_PER_SEC);

    return 0;
}