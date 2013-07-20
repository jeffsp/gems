/// @file algo.cc
/// @brief algorithms
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace std;
using namespace gems;

const string usage = "usage: algo";

#include <algorithm>

// generate() with lambda
void f1 ()
{
    vector<int> x (10);
    generate (x.begin (), x.end (), []() { return rand () % 100; });
    print (clog, x);
    // it might be clearer to do this
    for (auto &i : x) i = rand () % 100;
    print (clog, x);
}

// transform() with lambda
void f2 ()
{
    vector<int> a { 1, 2, 3, 4, 5 };
    vector<int> b { 0, 3, 3, 1, 7 };
    vector<bool> c (5);
    transform (a.begin (), a.end (), b.begin (), c.begin (),
        [] (int a, int b) { return a < b; });
    print (clog, c);
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
