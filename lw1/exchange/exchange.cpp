#include "stdafx.h"
#include <boost\phoenix.hpp>

using namespace std;
using namespace boost::phoenix::placeholders;

void ThrowError(size_t cost, size_t sum)
{
    if (cost < sum)
        throw domain_error("Not enought money");
    else
        throw range_error("You can not pay without putting!");
}

vector<unsigned> GetExchange(size_t const cost, vector<unsigned> coinValues)
{
    sort(coinValues.begin(), coinValues.end(), arg1 > arg2);
    vector<unsigned> result;
    size_t sum(0), tmpCost = cost;

    for (auto coin : coinValues)
    {
        if (tmpCost >= coin)
        {
            tmpCost -= coin;
            result.push_back(coin);
        }

        sum += coin;
    }

    if (tmpCost != 0)
    {
        ThrowError(tmpCost, sum);
    }

    return result;
}

bool ReadCost(size_t & cost)
{
    return static_cast<bool>(cin >> cost);
}

bool ReadCoinValues(vector<unsigned> & coinValues)
{
    size_t count;
    unsigned coin;
    bool reading = static_cast<bool>((cin >> count));
    coinValues.reserve(count);

    while (reading && count-- > 0)
    {
        cin >> coin;
        coinValues.push_back(coin);
    }

    return reading;
}

void PrintExchange(ostream & out, vector<unsigned> const& exchange)
{
    out << exchange.size() << " ";
    ostream_iterator<unsigned> outIt(out, " ");

    copy(exchange.begin(), exchange.end(), outIt);
    cout << endl;
}

void Exchange(size_t cost, vector<unsigned> const& coinValues)
{
    try
    {
        auto exchange = GetExchange(cost, coinValues);
        PrintExchange(cout, exchange);
    }
    catch (domain_error const&)
    {
        cout << -1 << endl;
    }
    catch (range_error const&)
    {
        cout << 0 << endl;
    }
}

int main(int argc, char* argv[])
{
    size_t cost;
    vector<unsigned> coinValues;

    if (ReadCost(cost) && ReadCoinValues(coinValues))
    {
        Exchange(cost, coinValues);
    }
    else
    {
        cout << "Input file corrupted!" << endl;
    }

    return 0;
}

