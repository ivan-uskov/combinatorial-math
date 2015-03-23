#include "stdafx.h"

using namespace std;

template <typename T>
ostream & operator << (ostream & out, list<T> const& contents)
{
    ostream_iterator<T> outIt(out, " ");
    copy(contents.begin(), contents.end(), outIt);

    return out;
}

void Iterate(list<size_t> & numbers)
{
    if (numbers.size() != 1)
    {
        auto it = numbers.begin();
        ++(*(it++));

        int sum = accumulate(it, numbers.end(), 0);
        numbers.erase(it, numbers.end());

        while (--sum > 0)
        {
            numbers.push_back(1);
        }
    }
}

void PrintCombines(size_t n)
{
    list<size_t> numbers(n, 1);

    while (numbers.size() != 1)
    {
        cout << numbers << endl;

        for (auto it = ++numbers.begin(); it != --numbers.end(); ++it)
        {
            auto next = *((++it)--);
            if (*it == next && (next + next) <= *numbers.begin())
            {
                auto next = (++it)--;
                *(it--) *= 2;
                numbers.erase(next);
                cout << numbers << endl;
            }
        }

        Iterate(numbers);
    }
}

int main(int argc, char* argv[])
{
    PrintCombines(5);
    return 0;
}

