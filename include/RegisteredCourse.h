#pragma once
#include "Course.h"
#include "utilities.h"
#include <algorithm>
#include <vector>

// Attendance Format
struct attendaceCount {
    date dateOfTaken;
    int status;
};

// Marks breakdown
struct marksOfCourse {
    double total;
    double mid;
    double final;
    double quiz1;
    double quiz2;
    double quiz3;
    double quiz4;
    marksOfCourse() {
        total = 0;
        mid = 0;
        final = 0;
        quiz1 = 0;
        quiz2 = 0;
        quiz3 = 0;
        quiz4 = 0;
    }
};

class RegisteredCourse : public Course {
  private:
    /*
      From Course Class
      offeredDept;
      title;
      courseCode;
      credits;
    */
    double percentageOfAttendace;
    int classCount;
    int presentCount;
    marksOfCourse marks;
    double courseProgress;
    string courseGrade;
    double courseCgpa;
    vector<attendaceCount> attendace;
    double courseTotalMarks;

  public:
    // Constructor
    RegisteredCourse(string offeredDept, string title, CourseCodeFormat courseCode, double credits, double percentageOfAttendace, int classCount, int presentCount);
    RegisteredCourse(CourseCodeFormat courseCode, string title, double credits, string offeredDept);

    // Setter Functions
    /*
        void set_title(string v_title);
        void set_course_code(CourseCodeFormat v_course_code);
        void set_credit(double v_credits);
    */
    // Attendace Functions
    void set_attendance(date d, int flag);
    void updatePercetage();

    // Marks Functions
    void set_quiz1Marks(double value);
    void set_quiz2Marks(double value);
    void set_quiz3Marks(double value);
    void set_quiz4Marks(double value);
    void set_midMarks(double value);
    void set_finalMarks(double value);

    void updateTotal();
    void updateGrade();

    // Getter Functions
    /*
        string get_title();
        string get_courseCode_Number();
        string get_courseCode_dept();
        string get_offeredDept();
        CourseCodeFormat get_courseCode();
        double get_credit();
    */
    double get_attendace();
    double get_quiz1Marks();
    double get_quiz2Marks();
    double get_quiz3Marks();
    double get_quiz4Marks();
    double get_midMarks();
    double get_finalMarks();
    string get_courseGrade();
    double get_courseCgpa();
    double get_courseProgress();
    int get_classCount();
    int get_presentCount();

    // Display Function
    void showDetails() {
        cout << title << " === " << courseCode.dept << "-" << courseCode.codeNumber << " " << credits << endl;
    }
    void showCourseResult();
};