#pragma once

#include "Course.h"
#include "Employee.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_COURSE_COUNT 10
class Teacher : public Employee {
  protected:
    string dept;

  public:
    vector<Course *> assignedCourses;
    // constructor
    Teacher();
    Teacher(string name, string address, date dob, string email, string id, date joinDate, double salary, string dept);

        // course related functions of teacher
    bool isAssigned(CourseCodeFormat courseCode);
    void assignCourse(Course *course);
    void takeAttendance(vector<Student *> &studentList);

    void set_quiz1Marks(CourseCodeFormat code, double value, Student &std);
    void set_quiz2Marks(CourseCodeFormat code, double value, Student &std);
    void set_quiz3Marks(CourseCodeFormat code, double value, Student &std);
    void set_quiz4Marks(CourseCodeFormat code, double value, Student &std);
    void set_midMarks(CourseCodeFormat code, double value, Student &std);
    void set_finalMarks(CourseCodeFormat code, double value, Student &std);
    void setMarks(vector<Student *> studentList);

    // void get_ongoing_course_info();
    // void deassign_course(CourseCodeFormat courseCode);
    // int get_course_count();

    // Display Information
    void displayInfo();
    string get_dept();
};