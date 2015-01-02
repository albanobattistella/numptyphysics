/*
 * This file is part of NumptyPhysics
 * Copyright (C) 2008 Tim Edmonds
 * Copyright (C) 2014 Thomas Perl <m@thp.io>
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
 *
 */


#include "Os.h"

#include "thp_format.h"


class OsFreeDesktop : public Os {
public:
    OsFreeDesktop()
        : Os()
    {
    }

    virtual bool openBrowser(const char *url)
    {
        if (url && system(thp::format("xdg-open '%s'", url).c_str()) == 0) {
            return true;
        }

        return false;
    }
};