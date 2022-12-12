#include "../src/serial/bubble.hpp"
#include "../src/serial/merge.hpp"
#include "../src/serial/quick.hpp"
#include "../src/helpers/unsorted-generator.hpp"

int main(int argc, char **argv)
{


    auto gen = new UnsortedGenerator();
    gen->generate_file(strtol(argv[1], NULL, 10), 0, strtol(argv[2], NULL, 10), 0);
    delete gen;

    // Serial

    auto bs = new BubbleSerial();
    bs->sort();
    delete bs;

    auto ms = new MergeSerial();
    ms->sort();
    delete ms;

    auto qs = new QuickSerial();
    qs->sort();
    delete qs;

    return 0;
}