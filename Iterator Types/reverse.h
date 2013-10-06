//
//  reverse.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/5/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef C___Programs_reverse_h
#define C___Programs_reverse_h

template <class Bi> void reverse(Bi begin, Bi end) {
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

#endif
