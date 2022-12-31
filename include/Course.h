#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Course Code
struct CourseCodeFormat {
    string dept;
    string codeNumber;
    CourseCodeFormat() {}
    CourseCodeFormat(string dept, string codeNumber) {
        this->dept = dept;
        this->codeNumber = codeNumber;
    }
};
class Course {
  protected:
    string offeredDept;
    string title;
    CourseCodeFormat courseCode;
    double credits;

  public:
    // Constructor
    Course();
    Course(CourseCodeFormat courseCode, string title, double credits, string offeredDept);

    // Setter Functions
    void set_title(string v_title);
    void set_course_code(CourseCodeFormat v_course_code);
    void set_credit(double v_credits);

    // Getter Functions
    string get_title();
    string get_courseCode_Number();
    string get_courseCode_dept();
    string get_offeredDept();
    CourseCodeFormat get_courseCode();
    double get_credit();
    string get_courseDept();

    // Display Functions
    void showCourseInfo();
};