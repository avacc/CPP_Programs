//
//  Student_info.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__student_info__
#define __C___Programs__student_info__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "median.h"

class Student_info {
    std::string n;
    double midterm, final;
    std::vector<double> homework;
public:
    Student_info();
    Student_info(std::istream&);
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
};

bool compare(const Student_info&, const Student_info&);
//std::istream& read(std::istream&, Student_info&);
//std::istream& read_hw(std::istream&, std::vector<double>&);
bool did_all_hw(const Student_info&);
bool students_did_hw(std::vector<Student_info>&);
bool students_did_hw();
void write_analysis(std::ostream&, const std::string&, double(const std::vector<Student_info>&),
                    const std::vector<Student_info>&, const std::vector<Student_info>&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);


#endif /* defined(__C___Programs__student_info__) */
