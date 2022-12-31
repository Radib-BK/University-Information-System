#pragma once
#include "BorrowedBooks.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

class Librarian : public Employee
{
/*from Employee class 
protected:
    string designation;
    string id;
    date joining_date;
    double salary;
    static int emp_count;

public:
    Employee();
    Employee(string v_name, string v_address, date v_dob, string v_email, string v_desig, string v_id, date v_joinDate, double v_salary);
    int get_empCount();
    void set_designation(string v_designation);
    void set_id(string v_id);
    void set_joiningDate(int join_day, int join_month, int join_year);
    void set_salary(double v_salary);
    string get_designation();
    string get_id();
    void show_joiningDate();
    double get_salary();
    void display_information(); */
public:
    Librarian();
    Librarian(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary);
    void processBorrowReq(vector<Book*> b, vector<Student*> std);
    void addBook(vector<Book*>& b);
    void viewBooks(vector<Book*> b);
    void removeBook(vector<Book*>& b);
};
