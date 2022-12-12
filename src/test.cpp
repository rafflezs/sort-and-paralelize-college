#include "./public/includes.hpp"

int main(int argc, char **argv)
{

    double start, stop;

    auto gen = new UnsortedGenerator();
    gen->generate_file(1000, 0, 1000, 0);
    delete gen;

    // Serial
    start = clock();
    auto ms = new MergeSerial();
    ms->sort();
    delete ms;
    stop = clock();
    printf("Merge Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    start = clock();
    auto qs = new QuickSerial();
    qs->sort();
    delete qs;
    stop = clock();
    printf("Quick Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    start = clock();
    auto bs = new BubbleSerial();
    bs->sort();
    delete bs;
    stop = clock();
    printf("Bubble Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    // // OpenMP
    // start = clock();
    // auto bomp = new BubbleOMP();
    // bomp->sort();
    // delete bomp;
    // stop = clock();
    // printf("Bubble OpenMP - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    // start = clock();
    // auto momp = new MergeOMP();
    // momp->sort();
    // delete momp;
    // stop = clock();
    // printf("Merge OpenMP - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    // start = clock();
    // auto qomp = new QuickOMP();
    // qomp->sort();
    // delete qomp;
    // stop = clock();
    // printf("Quick OpenMP - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    return 0;
}