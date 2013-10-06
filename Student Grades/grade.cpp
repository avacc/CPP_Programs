//
//  grade.cpp
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#include "grade.h"

using std::domain_error;    using std::vector;
using std::list;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            iter++;
    }
    
    return fail;
}

double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const vector<Student_info>& students) {
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}