#include "../../src/mpi/merge.hpp"

int main(int argc, char **argv)
{

    auto mmpi = new MergeMPI();
    mmpi->sort(argc, argv);
    delete mmpi;

    return 0;
}