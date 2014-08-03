/// @file io.cc
/// @brief io
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#include "gems.h"

using namespace std;

const string usage = "usage: io";

struct A
{
    A (const int i) : i (i) { }
    int i;
    // Note: The 'friend' specifier makes it not part of the class,
    // and is this neither public or private.
    friend std::ostream& operator<< (std::ostream &s, const A &a)
    {
        s << a.i;
        return s;
    }
    // ... for example, this has no effect:
    private:
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
    clog << a1 << endl;
    clog << a2 << endl;
    ss >> a2;
    clog << a2 << endl;
    assert (a2.i == 42);
}

#include <iterator>

void f2 ()
{
    stringstream ss;
    vector<int> x { 1, 2, 3, 4, 5 };
    copy (x.begin (), x.end (), ostream_iterator<int> (ss, " ")); // formatted
    clog << ss.str () << endl;
    assert (ss.str () == "1 2 3 4 5 ");
}

void f3 ()
{
    stringstream ss;
    vector<int> x { 0x31, 0x32, 0x33, 0x34, 0x35 };
    copy (x.begin (), x.end (), ostreambuf_iterator<char> (ss)); // unformatted
    clog << ss.str () << endl;
    assert (ss.str () == "12345");
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
