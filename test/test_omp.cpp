#include "../src/omp/bubble.hpp"
#include "../src/omp/merge.hpp"
#include "../src/omp/quick.hpp"

int main(int argc, char **argv)
{


    // OpenMP
    auto bomp = new BubbleOMP();
    bomp->sort();
    delete bomp;

    auto momp = new MergeOMP();
    momp->sort();
    delete momp;

    auto qomp = new QuickOMP();
    qomp->sort();
    delete qomp;

    return 0;
}