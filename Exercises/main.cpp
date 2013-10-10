//
//  main.cpp
//  Exercises
//
//  Created by Alex Vaccarino on 10/9/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

//#include <iostream>
//#include <string>
//#include <stdlib.h>
#include "Basins.h"
//#include "../Strings/string_funcs.cpp"

using std::cout;    using std::cin;
using std::endl;    using std::getline;
using std::string;


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


int main(int argc, const char * argv[])
{
    cout << "Please enter a square size: ";
    string line;
    getline(cin, line);
    
    const size_t size = (size_t) atoi(line.c_str());
//    cout << "Size (entered): " << size << endl;
    int** area = new int*[size];
//    cout << "Size (area): " << sizeof(area) << endl;
    for (int i = 0; i < size; i++)
        area[i] = new int[size];
//    cout << "Size (*area): " << sizeof(*area) << endl;
//    cout << "Size (**area): " << sizeof(**area) << endl;
//    cout << "Size (int): " << sizeof(int) << endl;
//    cout << "Size (int*): " << sizeof(int*) << endl;
//    cout << "Size (int**): " << sizeof(int**) << endl;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            cout << "(" << x << "," << y << ") : ";
            getline(cin, line);
            area[x][y] = atoi(trim(line).c_str());
        }
    }
    
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            cout << area[x][y] << " ";
        }
        cout << endl;
    }
    calculate_basins(area, size);
}



