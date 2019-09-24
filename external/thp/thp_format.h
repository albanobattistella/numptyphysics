/*
 * This file is part of NumptyPhysics <http://thp.io/2015/numptyphysics/>
 * Coyright (c) 2014 Thomas Perl <m@thp.io>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#ifndef THP_FORMAT_H
#define THP_FORMAT_H

#include <functional>
#include <string>

namespace thp {

class stringable {
public:
    virtual const char *c_str() const = 0;
};

/* allocating sprintf */
std::string format(const char *fmt, ...);
std::string format(const std::string &fmt, ...);
std::string format(const stringable &fmt, ...);

}; /* namespace thp */

#endif /* THP_FORMAT_H */
