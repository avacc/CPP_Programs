//
//  median.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__median__
#define __C___Programs__median__

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <stdexcept>

// double median(std::vector<double>);

template <class T>
T median(std::vector<T> v) {
    typedef typename std::vector<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    
    sort(v.begin(), v.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

#endif /* defined(__C___Programs__median__) */
