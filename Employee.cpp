#include "include/Employee.h"
#include <iostream>
#include <string>
using namespace std;

int Employee::emp_count = 0;

Employee::Employee() : Person(), designation(""), id(""), joining_date({1, 1, 2000}), salary(0.0) {
    emp_count++;
}

Employee::Employee(string v_name, string v_address, date v_dob, string v_email, string v_desig, string v_id, date v_joinDate, double v_salary) : Person(v_name, v_address, v_dob, v_email) {
    designation = v_desig;
    id = v_id;
    joining_date = {v_joinDate.day, v_joinDate.month, v_joinDate.year};
    salary = v_salary;
    emp_count++;
}

int Employee::get_empCount() {
    return emp_count;
}
void Employee::set_designation(string v_designation) {
    designation = v_designation;
}
void Employee::set_id(string v_id) {
    id = v_id;
}
void Employee::set_joiningDate(int join_day, int join_month, int join_year) {
    joining_date = {join_day, join_month, join_year};
}
void Employee::set_salary(double v_salary) {
    salary = v_salary;
}
string Employee::get_designation() {
    return designation;
}
string Employee::get_id() {
    return id;
}
void Employee::show_joiningDate() {
    show_date(joining_date);
}
double Employee::get_salary() {
    return salary;
}

date Employee::get_joiningDate() {
    return joining_date;
}
void Employee::display_information() {
    cout << "======================================================" << endl
         << endl;
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Designation: " << designation << endl;
    cout << "Joining Date: ";
    show_joiningDate();
    cout << endl;
    cout << "Address: " << address << endl;
    cout << "Email: " << email << endl;
    cout << "Date of Birth: ";
    show_dob();
    cout << endl;
    cout << "======================================================" << endl;
    /*May Change*/
}
