#pragma once
#ifndef COURSE
#define COURSE
#include "Course.h"
#endif

#ifndef PERSON
#define PERSON
#include "Person.h"
#endif

#ifndef REGISTEREDCOURSE
#define REGISTEREDCOURSE
#include "RegisteredCourse.h"
#endif

#ifndef BORROWEDBOOK
#define BORROWEDBOOK
#include "BorrowedBooks.h"
#endif

#ifndef UTILITIES
#define UTILITIES
#include "utilities.h"
#endif

#include <stdlib.h>
#include <vector>
class Accountant;
// Format for payment Status. If Clearence Flag is false that means there is pending payment.
struct paymentStatusFormat {
    bool paymentClearenceFlag;
    double pendingAmount;
};
class Student : public Person {
  protected:
    // Name     - from Person class
    // DOB      - from Person class
    // Email    - from Person Class
    // Address  - from Person class
    string id;
    string dept;
    int semester;
    string academic_year;
    static int std_count;
    paymentStatusFormat paymentStatus;
    // bool isBorrow; // if student has borrowed book

  public:
    vector<RegisteredCourse *> courseTaken; // Stores registered courses
    vector<BorrowedBooks *> booksTaken; // Stores Borrowed Books
    // Constructor
    Student();
    Student(string name, string address, date dob, string email, string dept, string academic_year, int serialOnDept);
    Student(string id, string name, date dob, string email, string address, string dept, int semester, string academic_year, bool paymentClearenceFlag, double pendingAmount); // int serialOnDept : Defining a serial number during registration based on specific department, and academic year.
    // Generate an unique id based on Academic Year, Department, Serial On Dept
    string generateId(int serialOnDept);

    // Show available course information based on Semester and offered dept
    void courseRegister(vector<Course *> c);
    bool checkRegisteredCourse(Course *c);
    void setRegisteredCourse(RegisteredCourse *temp);

    // Attendance taking
    // void addAttendace(assignedCourses[command - 1]->get_courseCode(), 1);
    void addAttendace(CourseCodeFormat code, int flag);

    // Library Access
    void libraryAccess(vector<Book *> b);
    bool checkBorrowedBooks(int registrationNo);
    void set_isBorrow(bool x);
    bool get_isBorrow();
    void set_booksTaken(BorrowedBooks *b);
    // Check if the student is registered
    // Setter Functions
    /*
      From Person Class
        void set_name(string name);
        void set_address(string address);
        void set_email(string email);
        void set_dob(int day, int month, int year);
    */
    void set_dept(string dept);
    void set_id(string v_id);
    void set_semester(int v_semester);
    void set_academic_year(int v_academic_year);
    void set_paymentClearenceFlag(bool flag);
    void set_pendingAmount(double pending_amount);
    void set_pending_Payment(double pending_amount);
    // Set marks - all function calls the specific course's set marks functions
    void set_quiz1Marks(CourseCodeFormat code, double value);
    void set_quiz2Marks(CourseCodeFormat code, double value);
    void set_quiz3Marks(CourseCodeFormat code, double value);
    void set_quiz4Marks(CourseCodeFormat code, double value);
    void set_midMarks(CourseCodeFormat code, double value);
    void set_finalMarks(CourseCodeFormat code, double value);

    // Getter Functions
    /*
      From Person Class
      string get_name();
      string get_address();
      string get_email();
      date get_dob();
    */
    string get_id();
    string get_dept();
    int get_semester();
    static int get_std_count();
    string get_academic_year();
    int get_course_count();
    int get_registeredCourseIndex(CourseCodeFormat code);
    bool get_paymentClearenceFlag();
    double get_pendingAmount();
    void paymentClearenceRequest(Accountant &acc);

    // Display Functions
    void display_information();
    void checkAttendance();
    void displayCourseResults();
    /*More functions will need to be added like result, payment status etc.*/
};
