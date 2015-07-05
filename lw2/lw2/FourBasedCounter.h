#pragma once
class FourBasedCounter
{
public:
    FourBasedCounter(int bits);

    void Inc();

    std::vector<unsigned> const& View()const;

private:
    void ToFourBase(unsigned i);

private:
    std::vector<unsigned> counter;
};

