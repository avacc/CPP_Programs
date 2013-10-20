//
//  Vec.cpp
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//


#include "Vec.h"


template <class T> void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(Vec<T>::size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(Vec<T>::const_iterator i, Vec<T>::const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate() {
    if (data) {
        // destroy, in reverse order, the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        
        // return all of the space that was allocated
        alloc.deallocate(data, limit - data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
}

template <class T> void Vec<T>::grow() {
    // when growing, allocate twice as much space as currently used
    size_type new_size = std::max(2*(limit - data), ptrdiff_t(1));
    
    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);
    
    // return the old space
    uncreate();
    
    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}