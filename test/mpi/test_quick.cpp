#include "../../src/mpi/quick.hpp"

int main(int argc, char **argv)
{

    auto qmpi = new QuickMPI();
    qmpi->sort(argc, argv);
    delete qmpi;

    return 0;
}