/// @file sleep.cc
/// @brief sleep x milliseconds
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2014-09-03

#include "gems.h"

using namespace std;

const string usage = "usage: sleep";

#include <chrono>
#include <thread>

void sleep (size_t x)
{
    this_thread::sleep_for(chrono::milliseconds(x));
}

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        sleep (10);

        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
    }
    return -1;
}
