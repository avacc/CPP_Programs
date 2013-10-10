//
//  Basins.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/9/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__Basins__
#define __C___Programs__Basins__

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <boost/tokenizer.hpp>


static void calculate_basins(int**);
static std::string lowest_plot(int**, int, int, char);
static bool is_out_of_bounds(int, int, int);


#endif /* defined(__C___Programs__Basins__) */
