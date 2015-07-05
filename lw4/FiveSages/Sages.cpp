#include "stdafx.h"
#include "Sages.h"

using namespace std;

Sages::Sages(size_t sageCount)
    : sageCount(sageCount)
    , sages(sageCount, 0)
    , distribution(0, sageCount - 1)
{
    if (sageCount < 3)
    {
        throw invalid_argument("Invalid sage count, minimum 3!");
    }
}

void Sages::AddRandDiner()
{
    auto readySages = GetReadySages();
    auto it = readySages.find(RandId());

    if (it != readySages.end())
    {
        sages[*it] = true;
    }
}

void Sages::FreeRandDiner()
{
    auto dinersSages = GetDinersSages();
    auto it = dinersSages.find(RandId());

    if (it != dinersSages.end())
    {
        sages[*it] = false;
    }
}

ostream & operator << (ostream & out, Sages const& rhs)
{
    for_each(rhs.sages.begin(), rhs.sages.end(), [&out](bool val){
        out << static_cast<int>(val) << "\t";
    });

    return out;
}

set<size_t> Sages::GetDinersSages()const
{
    set<size_t> diners;
    for (size_t i = 0; i < sageCount; ++i)
    {
        if (sages[i])
        {
            diners.insert(i);
        }
    }

    return diners;
}

set<size_t> Sages::GetReadySages()const
{
    set<size_t> readySages;
    if (!sages[sageCount - 1] && !sages[1])
    {
        readySages.insert(0);
    }

    if (!sages[sageCount - 2] && !sages[0])
    {
        readySages.insert(sageCount- 1);
    }

    for (size_t i = 1; i < sageCount - 2; ++i)
    {
        if (!sages[i - 1] && !sages[i + 1])
        {
            readySages.insert(i);
        }
    }

    return readySages;
}

size_t Sages::RandId()
{
    return distribution(generator);
}