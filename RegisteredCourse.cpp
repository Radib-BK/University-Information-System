#pragma once
#include "include/RegisteredCourse.h"

RegisteredCourse::RegisteredCourse(CourseCodeFormat courseCode, string title, double credits, string offeredDept) {
    this->courseCode = courseCode;
    this->title = title;
    this->credits = credits;
    this->offeredDept = offeredDept;
    this->classCount = 0;
    this->percentageOfAttendace = 0;
    this->marks = marksOfCourse();
    this->presentCount = 0;
    this->courseTotalMarks = credits * 100.00;
    this->courseProgress = 0;
    this->courseGrade = " ";
}

RegisteredCourse::RegisteredCourse(string offeredDept, string title, CourseCodeFormat courseCode, double credits, double percentageOfAttendace, int classCount, int presentCount) {
    this->courseCode = courseCode;
    this->title = title;
    this->credits = credits;
    this->offeredDept = offeredDept;
    this->classCount = classCount;
    this->percentageOfAttendace = percentageOfAttendace;
    this->presentCount = presentCount;
    this->courseTotalMarks = credits * 100.00;
    this->courseProgress = 0;
    this->courseGrade = " ";
}
void RegisteredCourse::set_attendance(date d, int flag) {
    attendaceCount temp = {d, flag};
    attendace.push_back(temp);
    classCount++;
    if (flag == 1)
        presentCount++;
    updatePercetage();
}
void RegisteredCourse::updatePercetage() {
    percentageOfAttendace = (presentCount * 1.0 / classCount * 1.0) * 100.00;
} // Getter Function
double RegisteredCourse::get_attendace() {
    return percentageOfAttendace;
}

// Marks Functions
void RegisteredCourse::set_quiz1Marks(double value) {
    marks.quiz1 = value;
    updateTotal();
}
void RegisteredCourse::set_quiz2Marks(double value) {
    marks.quiz2 = value;
    updateTotal();
}
void RegisteredCourse::set_quiz3Marks(double value) {
    marks.quiz3 = value;
    updateTotal();
}
void RegisteredCourse::set_quiz4Marks(double value) {
    marks.quiz4 = value;
    updateTotal();
}
void RegisteredCourse::set_midMarks(double value) {
    marks.mid = value;
    updateTotal();
}
void RegisteredCourse::set_finalMarks(double value) {
    marks.final = value;
    updateTotal();
}

void RegisteredCourse::updateTotal() {
    double temp[4] = {marks.quiz1, marks.quiz2, marks.quiz3, marks.quiz4};
    sort(temp, temp + 4);
    marks.total = marks.mid + marks.final;
    for (int i = 3; i > 0; i--)
        marks.total += temp[i];

    courseProgress = (marks.total * 1.0 / courseTotalMarks * 1.0) * 100;
    updateGrade();
}

void RegisteredCourse::updateGrade() {
    if (courseProgress >= 80.00) {
        courseGrade = "A+";
        courseCgpa = 4.00;
    }

    else if (courseProgress >= 75.00) {
        courseGrade = "A";
        courseCgpa = 3.75;
    }

    else if (courseProgress >= 70.00) {
        courseGrade = "A-";
        courseCgpa = 3.50;
    } else if (courseProgress >= 65.00) {
        courseGrade = "B+";
        courseCgpa = 3.25;
    } else if (courseProgress >= 60.00) {
        courseGrade = "B";
        courseCgpa = 3.00;
    } else if (courseProgress >= 55.00) {
        courseGrade = "B-";
        courseCgpa = 2.75;
    } else if (courseProgress >= 50.00) {
        courseGrade = "C";
        courseCgpa = 2.50;
    } else if (courseProgress >= 40.00) {
        courseGrade = "D";
        courseCgpa = 2.25;
    } else if (courseProgress < 40.00) {
        courseGrade = "F";
        courseCgpa = 0.00;
    }
}

// Getter Functions
double RegisteredCourse::get_quiz1Marks() {
    return marks.quiz1;
}
double RegisteredCourse::get_quiz2Marks() {
    return marks.quiz2;
}
double RegisteredCourse::get_quiz3Marks() {
    return marks.quiz3;
}
double RegisteredCourse::get_quiz4Marks() {
    return marks.quiz4;
}
double RegisteredCourse::get_midMarks() {
    return marks.mid;
}
double RegisteredCourse::get_finalMarks() {
    return marks.final;
}
string RegisteredCourse::get_courseGrade() {
    return courseGrade;
}
double RegisteredCourse::get_courseCgpa() {
    return courseCgpa;
}
double RegisteredCourse::get_courseProgress() {
    return courseProgress;
}

int RegisteredCourse::get_classCount() {
    return classCount;
}
int RegisteredCourse::get_presentCount() {
    return presentCount;
}
void RegisteredCourse::showCourseResult() {
    cout << "Quiz1 : " << get_quiz1Marks() << endl;
    cout << "Quiz2 : " << get_quiz2Marks() << endl;
    cout << "Quiz3 : " << get_quiz3Marks() << endl;
    cout << "Quiz4 : " << get_quiz4Marks() << endl;
    cout << "Mid : " << get_midMarks() << endl;
    cout << "Final : " << get_finalMarks() << endl;
    cout << "Progress : " << get_courseProgress() << "%" << endl;
    cout << "Grade : " << get_courseGrade() << endl;
    cout << "CGPA : " << get_courseCgpa() << endl;
}
