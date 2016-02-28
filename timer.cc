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

class timer
{
    public:
    timer ()
        : start (std::chrono::system_clock::now ())
    {
    }
    double operator() () const
    {
        return elapsed_seconds ();
    }
    double elapsed_seconds () const
    {
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now ();
        std::chrono::duration<double> elapsed_seconds = end - start;
        return elapsed_seconds.count ();
    }
    private:
    std::chrono::time_point<std::chrono::system_clock> start;
};

int main (int argc, char **argv)
{
    try
    {
        if (argc != 1)
            throw runtime_error (usage);

        timer t;
        gems::sleep (100);
        clog << t() << "s elapsed" << endl;

        clog << "success" << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
    }
    return -1;
}
