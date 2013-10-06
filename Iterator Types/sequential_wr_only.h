//
//  sequential_wr_only.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/5/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef C___Programs_sequential_wr_only_h
#define C___Programs_sequential_wr_only_h

template <class In, class Out>
Out copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}


#endif
