//
//  string_funcs.cpp
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#include "string_funcs.h"

using std::string;      using std::vector;
using std::isspace;     using std::max;

vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            i++;
        
        string_size j = i;
        while (j != s.size() && !isspace(s[i]))
            j++;
        
        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}


string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); i++)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    ret.push_back(border);
    
    for (vector<string>::size_type i = 0; i != v.size(); i++) 
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    
    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    vector<string> ret = top;
    
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;
    
    string::size_type width1 = width(left) + 1;
    vector<string>::size_type i = 0, j = 0;
    
    while (i != left.size() || j != right.size()) {
        string s;
        
        if (i != left.size())
            s = left[i++];
        
        s += string(width1 - s.size(), ' ');
        
        if (j != right.size())
            s += right[j++];
        
        ret.push_back(s);
    }
    return ret;
}

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c) {
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    
    typedef string::const_iterator iter;
    
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            
            while (beg != b && isalpha(beg[-1]))
                beg--;
            
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        i += sep.size();
    }
    return e;
}

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    while (b != e) {
        b = url_beg(b, e);
        
        if (b != e) {
            iter after = url_end(b, e);
            
            ret.push_back(string(b, after));
            
            b = after;
        }
    }
    return ret;
}

static inline string& ltrim(string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace))));
    return s;
}

static inline string& rtrim(string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

static inline string& trim(string& s) {
    return ltrim(rtrim(s));
}