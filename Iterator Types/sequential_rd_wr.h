//
//  sequential_rd_wr.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/5/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef C___Programs_sequential_rd_wr_h
#define C___Programs_sequential_rd_wr_h

template <class For, class X>
void replace(For beg, For end, const X& x, const X& y) {
    while (beg != end) {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

#endif
