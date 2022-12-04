#include "./public/includes.hpp"

int main()
{
    auto gen = new UnsortedGenerator();
    gen->generate_file(10, 0, 10, 0);
    delete gen;

    auto ss = new SelectSerial();
    ss->sort();
    delete ss;

    auto ms = new MergeSerial();
    ms->sort();
    
    auto qs = new QuickSerial();
    qs->sort();
    
    auto bs = new BubbleSerial();
    bs->sort();

    auto bomp = new BubbleOMP();
    bomp->sort();

    return 0;
}