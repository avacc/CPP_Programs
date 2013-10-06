//
//  grade.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__grade__
#define __C___Programs__grade__

#include <vector>
#include <stdexcept>
#include <list>
#include "median.h"
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);

#endif /* defined(__C___Programs__grade__) */
