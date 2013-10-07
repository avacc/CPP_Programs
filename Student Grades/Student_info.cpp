//
//  Student_info.cpp
//  C++ Programs
//
//  Created by Alex Vaccarino on 9/14/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#include "Student_info.h"

using std::istream;     using std::vector;
using std::cin;         using std::cout;
using std::endl;        using std::ostream;
using std::string;      using std::list;
using std::domain_error;


Student_info::Student_info(): midterm(0), final(0) { }

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        
        double x;
        while (in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}
 
Student_info::Student_info(istream& is) {
    read(is);
}

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has no homework");
    return grade(midterm, final, median(hw));
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}

//istream& read(istream& is, Student_info& s) {
//    is >> s.name >> s.midterm >> s.final;
//
//    read_hw(is, s.homework);
//    return is;
//}
//
//
//bool did_all_hw(const Student_info& s) {
//    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
//}
//
//bool students_did_hw(vector<Student_info>& students) {
//    vector<Student_info>::iterator iter = students.begin();
//    vector<Student_info> didnt;
//    
//    while (iter != students.end()) {
//        if (!did_all_hw(*iter))
//            didnt.push_back(*iter);
//        iter++;
//    }
//    
//    if (didnt.empty()) {
//        cout << "Every student did all of the homework!" << endl;
//        return true;
//    }
//    cout << "No student did all of the homework!" << endl;
//    return false;
//}
//
//bool students_did_hw() {
//    vector<Student_info> did, didnt;
//    Student_info student;
//    
//    while (read(cin, student)) {
//        if (did_all_hw(student))
//            did.push_back(student);
//        else
//            didnt.push_back(student);
//    }
//    
//    if (did.empty()) {
//        cout << "No student did all of the homework!" << endl;
//        return false;
//    }
//    
//    if (didnt.empty()) {
//        cout << "Every student did all of the homework!" << endl;
//        return true;
//    }
//}
//
//void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
//                    const vector<Student_info>& did, const vector<Student_info>& didnt) {
//    out << name << ": median(did) = " << analysis(did) <<
//                ", median(didnt) = " << analysis(didnt) << endl;
//}
//*/
//
//
//double grade(const Student_info& s) {
//    return grade(s.midterm, s.final, s.homework);
//}
//
//bool fgrade(const Student_info& s) {
//    return grade(s) < 60;
//}
//*/
//
//
//list<Student_info> extract_fails(list<Student_info>& students) {
//    list<Student_info> fail;
//    list<Student_info>::iterator iter = students.begin();
//    
//    while (iter != students.end()) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else
//            iter++;
//    }
//    
//    return fail;
//}
//
//double grade_aux(const Student_info& s) {
//    try {
//        return grade(s);
//    } catch (domain_error) {
//        return grade(s.midterm, s.final, 0);
//    }
//}
//
//double median_analysis(const vector<Student_info>& students) {
//    vector<double> grades;
//    
//    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
//    return median(grades);
//}
