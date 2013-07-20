/// @file algo.cc
/// @brief algorithms
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace gems;
using namespace std;

const string usage = "usage: algo";

#include <algorithm>

void f1 ()
{
    vector<int> x (100);
    generate (x.begin (), x.end (), rand);
}

void f2 ()
{
    vector<int> a { 1, 2, 3, 4, 5 };
    vector<int> b { 0, 3, 3, 1, 7 };
    vector<bool> c (5);
    transform (a.begin (), a.end (), b.begin (), c.begin (),
        [] (int a, int b) { return a < b; });
    assert (c == vector<bool> ({ 0, 1, 0, 0, 1 }));
}

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        f1 ();
        f2 ();
        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
