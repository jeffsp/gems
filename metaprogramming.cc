/// @file algo.cc
/// @brief algorithms
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace std;

const string usage = "usage: algo";

#include <algorithm>

struct A { void print () { clog << "A" << endl; } };
struct B { void print () { clog << "B" << endl; } };
struct C { void print () { clog << "C" << endl; } };

template<unsigned N>
struct iter
{
    template<typename T>
    static void f (T &t)
    {
        iter<N-1>::f (t);
        get<N> (t).print ();
    }
};

template<>
struct iter<0>
{
    template<typename T>
    static void f (T &t)
    {
        get<0> (t).print ();
    }
};

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        // iterate a tuple
        tuple <A,B,C> t;
        iter<tuple_size<decltype(t)>::value-1>::f (t);
        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
