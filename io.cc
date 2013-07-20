/// @file io.cc
/// @brief io
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace gems;
using namespace std;

const string usage = "usage: io";

struct A
{
    A (const int i) : i (i) { }
    int i;
    friend std::ostream& operator<< (std::ostream &s, const A &a)
    {
        s << a.i;
        return s;
    }
    friend std::istream& operator>> (std::istream &s, A &a)
    {
        s >> a.i;
        return s;
    }
};

void f1 ()
{
    stringstream ss;
    A a1 { 42 };
    ss << a1;
    A a2 { 24 };
    ss >> a2;
    assert (a2.i == 42);
}

#include <iterator>

void f2 ()
{
    stringstream ss;
    vector<int> x { 1, 2, 3, 4, 5 };
    copy (x.begin (), x.end (), ostream_iterator<int> (ss, "\n")); // formatted
    assert (ss.str () == "1\n2\n3\n4\n5\n");
}

void f3 ()
{
    stringstream ss;
    vector<int> x { 1, 2, 3, 4, 5 };
    copy (x.begin (), x.end (), ostreambuf_iterator<char> (ss)); // unformatted
    assert (ss.str () == "\x01\x02\x03\x04\x05");
}

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        f1 ();
        f2 ();
        f3 ();
        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
