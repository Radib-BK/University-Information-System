#include "include/Course.h"
using namespace std;

// Constructor
Course::Course() : title(""), credits(0) {}
Course::Course(CourseCodeFormat courseCode, string title, double credits, string offeredDept) {
    this->title = title;
    this->courseCode = courseCode;
    this->credits = credits;
    this->offeredDept = offeredDept;
}

// Setter Functions
void Course::set_title(string v_subject_code) {
    title = v_subject_code;
}
void Course::set_course_code(CourseCodeFormat v_course_code) {
    courseCode = v_course_code;
}
void Course::set_credit(double v_credits) {
    credits = v_credits;
}

// Getter Functions
string Course::get_title() {
    return title;
}
string Course::get_courseCode_Number() {
    return courseCode.codeNumber;
}
string Course::get_courseCode_dept() {
    return courseCode.dept;
}
double Course::get_credit() {
    return credits;
}
CourseCodeFormat Course::get_courseCode() {
    return courseCode;
}
string Course::get_offeredDept() {
    return offeredDept;
}
string Course::get_courseDept() {
    return offeredDept;
}

// Display Functions
void Course::showCourseInfo() {
    cout << "Dept " << offeredDept << endl;
    cout << "Title " << title << endl;
    cout << "Course Code " << courseCode.dept << "-" << courseCode.codeNumber << endl;
    cout << "Credit " << credits << endl;
}