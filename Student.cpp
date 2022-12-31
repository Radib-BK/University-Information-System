#pragma once
#include "include/Student.h"
#include "include/Accountant.h"
#include <iostream>
#include <string>
using namespace std;

int Student::std_count = 0;

// Constructor
Student::Student() : Person(), id(""), semester(0), academic_year("2000") {}
Student::Student(string name, string address, date dob, string email, string dept, string academic_year, int serialOnDept) {
    std_count++;
    this->name = name;
    this->address = address;
    this->email = email;
    this->dob = {dob.day, dob.month, dob.year};
    this->dept = dept;
    // this->isBorrow = false;
    semester = 1;
    this->academic_year = academic_year;
    id = generateId(serialOnDept);
    paymentStatus.paymentClearenceFlag = true;
    paymentStatus.pendingAmount = 0.0;
}

Student::Student(string id, string name, date dob, string email, string address, string dept, int semester, string academic_year, bool paymentClearenceFlag, double pendingAmount) {
    std_count++;
    this->name = name;
    this->address = address;
    this->email = email;
    this->dob = {dob.day, dob.month, dob.year};
    this->dept = dept;
    this->semester = semester;
    this->academic_year = academic_year;
    this->id = id;
    paymentStatus.paymentClearenceFlag = paymentClearenceFlag;
    paymentStatus.pendingAmount = pendingAmount;
}
// Generate Unique ID
string Student::generateId(int serialOnDept) {
    id = "";
    id += academic_year[academic_year.size() - 2];
    id += academic_year[academic_year.size() - 1];
    id += '0';
    id += '0';

    if (dept == "CSE")
        id += '4';
    else if (dept == "EEE")
        id += '2';
    else if (dept == "CEE")
        id += '5';
    else if (dept == "MPE")
        id += '3';
    else if (dept == "BTM")
        id += '6';

    id += "11";
    if (serialOnDept < 10) {
        id += "0";
    }
    id += to_string(serialOnDept);
    return id;
    /* string tempStr = "";
    int tempInt = serialOnDept;
    for (int i = 0; i < 2; i++) {
        tempStr += (tempInt % 10) + '0';
        tempInt /= 10;
    }
    for (int i = tempStr.size() - 1; i >= 0; i--) {
        id += tempStr[i];
    }

    return id; */
}

// Course Registration
void Student::courseRegister(vector<Course *> c) {
    vector<Course *> temp;
    cout << "==========================================" << endl;
    cout << "-- Course List --" << endl;
    // This loop listing all the courses those are matched with student semester and dept and also keeps them in a temporary vector.
    for (int i = 0, j = 1; i < c.size(); i++) {
        if (semester + '0' == (c[i]->get_courseCode_Number())[1] && dept == c[i]->get_offeredDept()) {
            temp.push_back(c[i]);
            cout << "\t";
            cout << j++ << ": " << c[i]->get_courseCode_dept() << " " << c[i]->get_courseCode_Number() << endl;
        }
    }

    int command;
    char commandBuffer;
    // This loop registering the courses.
    while (1) {
        cout << "Choose Course (0 for exit) : ";
        cin >> command;
        if (command == 0)
            break;
        if (checkRegisteredCourse(temp[command - 1])) {
            cout << "Already registered" << endl;
            continue;
        }
        RegisteredCourse *tempReg = new RegisteredCourse(temp[command - 1]->get_courseCode(), temp[command - 1]->get_title(), temp[command - 1]->get_credit(), temp[command - 1]->get_offeredDept());
        courseTaken.push_back(tempReg);
    }
}

// Check if the course is already registered
bool Student::checkRegisteredCourse(Course *c) {
    for (int i = 0; i < courseTaken.size(); i++) {
        if (c->get_courseCode_dept() == courseTaken[i]->get_courseCode_dept() && c->get_courseCode_Number() == courseTaken[i]->get_courseCode_Number())
            return true;
    }
    return false;
}
void Student::setRegisteredCourse(RegisteredCourse *temp) {
    courseTaken.push_back(temp);
}
// Add attendance, called from teacher object.
void Student::addAttendace(CourseCodeFormat code, int flag) {
    date d = {1, 1, 2000};
    for (int i = 0; i < courseTaken.size(); i++) {
        if (code.dept == courseTaken[i]->get_courseCode_dept() && code.codeNumber == courseTaken[i]->get_courseCode_Number()) {
            courseTaken[i]->set_attendance(d, flag);
            break;
        }
    }
}

// Library Access
void Student::libraryAccess(vector<Book *> b) {
    int bookCommand;
    char bookCommandBuffer;
    system("CLS");
    while (1) {
        cout << "====================================================" << endl;
        cout << "Borrowed Books" << endl;
        /* if (booksTaken.size() == 0)
        {
            set_isBorrow(false);
        } */
        for (int i = 0; i < booksTaken.size(); i++) {
            if (booksTaken[i]->get_borrow_grant_status()) // if the librarian grants req then status will be true
            {
                cout << i + 1 << " : " << booksTaken[i]->get_title() << "\t\t--- " << booksTaken[i]->get_publisher() << "\t\t--- Return Date : ";
                show_date(booksTaken[i]->get_returnDate());
                cout << endl;
            }
        }
        cout << "====================================================" << endl;
        cout << "-- Available Books in Library --" << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << "\t" << i + 1 << " : " << b[i]->get_title() << "\t\t--- " << b[i]->get_publisher() << "\t\t--- " << b[i]->get_available_copies() << " Copies" << endl;
        }
        // date d1 = {1, 1, 2022};  borrow date
        date d1;
        time_t t = time(nullptr);
        tm *now = localtime(&t);
        d1.day = now->tm_mday;
        d1.month = now->tm_mon + 1;
        d1.year = now->tm_year + 1900;

        cout << "====================================================" << endl;
        cout << "Borrow Book. Enter Book No (0 For go back): " << endl;
        cin >> bookCommandBuffer;
        bookCommand = bookCommandBuffer - '0';
        if (bookCommand == 0)
            return;
        if (checkBorrowedBooks(b[bookCommand - 1]->get_registration_number())) {
            system("CLS");
            cout << "\n\n!!! Book Already Borrowed or Requested !!!\n\n"
                 << endl;
            continue;
        }

        // Creating a new borrowed book from book
        BorrowedBooks *temp = new BorrowedBooks(b[bookCommand - 1]->get_title(), b[bookCommand - 1]->get_author(), b[bookCommand - 1]->get_publisher(), b[bookCommand - 1]->get_genre(), b[bookCommand - 1]->get_total_copies(), b[bookCommand - 1]->get_registration_number(), false, d1);
        booksTaken.push_back(temp); // Pushing to bookstaken vector.
        // set_isBorrow(true);
        system("CLS");
    }
}

// Check if the book is already taken.
bool Student::checkBorrowedBooks(int registrationNo) {
    for (int i = 0; i < booksTaken.size(); i++) {
        if (booksTaken[i]->get_registration_number() == registrationNo) {
            return true;
        }
    }
    return false;
}
void Student::set_booksTaken(BorrowedBooks *b) {
    booksTaken.push_back(b);
}
// Setter Functions
void Student::set_id(string v_id) {
    id = v_id;
}
void Student::set_semester(int v_semester) {
    semester = v_semester;
}
void Student::set_academic_year(int v_academic_year) {
    academic_year = v_academic_year;
}
void Student::set_dept(string dept) {
    this->dept = dept;
}
void Student::set_paymentClearenceFlag(bool flag) {
    paymentStatus.paymentClearenceFlag = flag;
}
void Student::set_pendingAmount(double pending_amount) {
    paymentStatus.pendingAmount = pending_amount;
}
// Set marks for
void Student::set_quiz1Marks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_quiz1Marks(value);
}
void Student::set_quiz2Marks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_quiz2Marks(value);
}
void Student::set_quiz3Marks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_quiz3Marks(value);
}
void Student::set_quiz4Marks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_quiz4Marks(value);
}
void Student::set_midMarks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_midMarks(value);
}
void Student::set_finalMarks(CourseCodeFormat code, double value) {
    int index = get_registeredCourseIndex(code);
    courseTaken[index]->set_finalMarks(value);
}
void Student::set_pending_Payment(double pending_amount) {
    if (pending_amount > 0)
        set_paymentClearenceFlag(false);
    set_pendingAmount(pending_amount);
}
/* oid Student::set_isBorrow(bool x)
{
void Student::set_isBorrow(bool x) {
    isBorrow = x;
} */
// Getter Functions
int Student::get_semester() {
    return semester;
}
string Student::get_academic_year() {
    return academic_year;
}
string Student::get_id() {
    return id;
}
string Student::get_dept() {
    return dept;
}
int Student::get_std_count() {
    return std_count;
}
int Student::get_course_count() {
    return courseTaken.size();
}
int Student::get_registeredCourseIndex(CourseCodeFormat code) {
    for (int i = 0; i < courseTaken.size(); i++) {
        if (code.dept == courseTaken[i]->get_courseCode_dept() && code.codeNumber == courseTaken[i]->get_courseCode_Number()) {
            return i;
        }
    }
}

bool Student::get_paymentClearenceFlag() {
    return paymentStatus.paymentClearenceFlag;
}
double Student::get_pendingAmount() {
    return paymentStatus.pendingAmount;
}
/* bool Student::get_isBorrow()
{
bool Student::get_isBorrow() {
    return isBorrow;
} */

void Student::paymentClearenceRequest(Accountant &acc) {
    acc.setPaymentRequest(*this);
}

// Display Functions
void Student::display_information() {
    cout << "================================================" << endl;
    cout << "Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Academic Year: " << academic_year << endl;
    cout << "Current Semester: " << semester << endl;
    cout << "Courses Taken: " << endl;
    for (int i = 0; i < courseTaken.size(); i++) {
        cout << "  -- ";
        courseTaken[i]->showDetails();
    }
    cout << "Address: " << address << endl;
    cout << "Email: " << email << endl;
    cout << "Department : " << dept << endl;
    cout << "Date of Birth: ";

    show_dob();
    cout << endl;

    cout << "Payment Status : ";
    if (get_paymentClearenceFlag())
        cout << "No Pending" << endl;
    else
        cout << "Pending (" << paymentStatus.pendingAmount << ")" << endl;
    cout << "================================================" << endl
         << endl;
    /*May Change*/
}

void Student::checkAttendance() {
    system("CLS");
    int command;
    char commandBuffer;
    cout << "================================================" << endl
         << endl;
    for (int i = 0; i < courseTaken.size(); i++) {
        cout << courseTaken[i]->get_title() << ": " << courseTaken[i]->get_attendace() << endl;
    }
    cout << endl
         << "================================================" << endl
         << endl;
    cout << "Enter 0 for back" << endl;
    cin >> commandBuffer;
    command = commandBuffer - '0';
    if (command == 0)
        return;
}

void Student::displayCourseResults() {

    system("CLS");
    int command;
    char commandBuffer;
    for (int i = 0; i < courseTaken.size(); i++) {
        cout << endl
             << "===========================================" << endl
             << endl;
        cout << i + 1 << ":" << endl;
        cout << courseTaken[i]->get_title() << ":" << endl;
        courseTaken[i]->showCourseResult();
    }
    cout << endl
         << "===========================================" << endl
         << endl;
    cout << "Enter 0 for back : ";
    cin >> commandBuffer;
    command = commandBuffer - '0';
    if (command == 0)
        return;
}