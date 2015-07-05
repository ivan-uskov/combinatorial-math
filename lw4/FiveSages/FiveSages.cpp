#include "stdafx.h"
#include "Sages.h"

using namespace std;

unsigned InitIterationCount(int argc, char* argv[])
{
    unsigned count = 200;
    if (argc == 2)
    {
        count = atoi(argv[1]);
    }

    return count;
}

int main(int argc, char* argv[])
{
    try
    {
        auto iterations = InitIterationCount(argc, argv);
        ofstream logFile("sages.log");
        Sages sages(5);

        while (iterations-- > 0)
        {
            sages.AddRandDiner();
            logFile << sages << endl;

            sages.FreeRandDiner();
            logFile << sages << endl;
        }
    }
    catch (exception const& e)
    {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}

