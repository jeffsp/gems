/// @file sleep.cc
/// @brief sleep x milliseconds
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2014-09-03

#include "gems.h"

using namespace std;

const string usage = "usage: sleep";

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        gems::sleep (10);

        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
    }
    return -1;
}
