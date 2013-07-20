/// @file main_boilerplate.cc
/// @brief main boilerplate
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace std;

const string usage = "usage: main_boilerplate";

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
