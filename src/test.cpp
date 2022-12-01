#include "./serial/bubble.hpp"
#include "./serial/merge.hpp"
#include "./serial/quick.hpp"
#include "./serial/select.hpp"
#include "./helpers/unsorted-generator.hpp"

int main()
{
    auto gen = new UnsortedGenerator();
    gen->generate_file(10, 0, 10, 0);
    delete gen;

    auto ss = new SelectSerial();
    ss->sort();

    // auto ms = new MergeSerial();
    // ms->sort();
    
    // auto qs = new QuickSerial();
    // qs->sort();
    
    // auto bs = new BubbleSerial();
    // bs->sort();

    return 0;
}