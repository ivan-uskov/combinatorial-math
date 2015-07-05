#include "stdafx.h"
#include "FourBasedCounter.h"

using namespace std;

FourBasedCounter::FourBasedCounter(int bits)
    : counter(bits, 0)
{
}

vector<unsigned> const& FourBasedCounter::View()const
{
    return counter;
}

void FourBasedCounter::Inc()
{
    ++counter[0];
    ToFourBase(0);
}

void FourBasedCounter::ToFourBase(unsigned i)
{
    auto nextI = i + 1;

    if (counter[i] > 3)
    {
        if (nextI == counter.size())
        {
            throw out_of_range("Counter overflow");
        }

        counter[i] -= 4;
        ++counter[nextI];

        ToFourBase(nextI);
    }
}
