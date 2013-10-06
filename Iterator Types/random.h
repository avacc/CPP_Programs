//
//  random.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/5/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef C___Programs_random_h
#define C___Programs_random_h

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x) {
    while (begin < end) {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking only in that part
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        // if we got here, then *mid == x so we're done
        else return true;
    }
    return false;
}

#endif
