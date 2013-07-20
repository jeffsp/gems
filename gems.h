/// @file gems.h
/// @brief gems header file
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-07-20

#ifndef GEMS_H
#define GEMS_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace gems
{

template<typename V>
std::ostream& print (std::ostream &s, const V &v)
{
    for (auto i : v)
        s << ' ' << i;
    s << std::endl;
    return s;
}

}

#endif
