#pragma once

class Sages
{
public:
    Sages(size_t sageCount = 3);

    void AddRandDiner();
    void FreeRandDiner();

    friend std::ostream & operator << (std::ostream & out, Sages const& rhs);

private:
    std::set<size_t> GetReadySages()const;
    std::set<size_t> GetDinersSages()const;

    size_t RandId();

    std::vector<bool> sages;
    size_t sageCount, iterationsCount;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
};

std::ostream & operator << (std::ostream & out, Sages const& rhs);