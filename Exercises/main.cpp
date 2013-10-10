//
//  main.cpp
//  Exercises
//
//  Created by Alex Vaccarino on 10/9/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Basins.h"
#include "../Strings/string_funcs.h"

using std::cout;    using std::cin;
using std::endl;    using std::getline;
using std::string;

int main(int argc, const char * argv[])
{
    cout << "Please enter a square size: ";
    string line;
    getline(cin, line);
    
    int size = atoi(line.c_str());
    int** area = new int*[size];
    for (int i = 0; i < size; i++)
        area[i] = new int[size];
    
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            cout << "(" + x + "," + y + ") : ";
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
    calculate_basins(area);
}

