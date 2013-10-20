//
//  Vec.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__Vec__
#define __C___Programs__Vec__

#include <iostream>
#include <memory>

template <class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    
    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }
    ~Vec() { uncreate(); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }  // copy constructor
    
    size_type size() const { return avail - data; }
    
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    
    Vec& operator=(const Vec& rhs) {
        // check for self-assignment
        if (&rhs != this) {
            // free the array on the left-hand side
            uncreate();
            
            // copy the elements from the right-hand to the left-hand side
            create(rhs.begin(), rhs.end());
        }
        return *this;
    }
    
    void push_back(const T& val) {
        if (avail == limit)
            grow();
        unchecked_append(val);
    }
private:
    iterator data;  // pointer to the first element in the Vec
    iterator avail; // pointer to one passed the last constructed element
    iterator limit; // pointer to one passed the last available element
        
    std::allocator<T> alloc;
    
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    
    void uncreate();
    
    void grow();
    void unchecked_append(const T&);
};


#endif /* defined(__C___Programs__Vec__) */
