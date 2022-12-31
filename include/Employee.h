#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Employee : public Person {
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
    date get_joiningDate();
    double get_salary();
    void display_information();
};
