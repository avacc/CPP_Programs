//
//  string_funcs.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__string_funcs__
#define __C___Programs__string_funcs__

#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <cctype>

// std::vector<std::string> split(const std::string&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
bool is_palindrome(const std::string&);
bool not_url_char(char);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

template <class Out>
void split(const std::string& str, Out os) {
    
    typedef std::string::const_iterator iter;
    
    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = std::find_if(i, str.end(), !std::isspace(*i));
        
        // find end of the next word
        iter j = std::find_if(i, str.end(), std::isspace(*i));
        
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = std::string(i, j);
        
        i = j;
    }
}

#endif /* defined(__C___Programs__string_funcs__) */
