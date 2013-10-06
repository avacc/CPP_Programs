//
//  main.cpp
//  Strings
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#include <iostream>
#include "string_funcs.h"

using std::string;      using std::vector;
using std::cin;         using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    string s;
    
    cout << "Please enter a string : ";
    
    vector<string> x;
    while (cin >> s)
        x.push_back(s);
    cout << endl;
    
    vector<string> temp = hcat(frame(hcat(frame(x), frame(x))), frame(hcat(frame(x), frame(x))));
    for (vector<string>::size_type i = 0; i != temp.size(); i ++)
            cout << temp[i] << endl;
    
    return 0;
}

