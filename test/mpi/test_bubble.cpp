#include "../../src/mpi/bubble.hpp"

int main(int argc, char **argv)
{

    auto bmpi = new BubbleMPI();
    bmpi->sort(argc, argv);
    delete bmpi;

    return 0;
}