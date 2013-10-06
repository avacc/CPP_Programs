//
//  sequential_rd_only.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/5/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef C___Programs_sequential_rd_only_h
#define C___Programs_sequential_rd_only_h

#include <iostream>

template <class In, class X> In find(In begin, In end, const X& x) {
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}


#endif
