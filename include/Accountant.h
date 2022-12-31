#pragma once
#define ACCOUNTANT
#ifndef EMPLOYEE
#define EMPLOYEE
#include "Employee.h"
#endif
#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif
#ifndef TEACHER
#define TEACHER
#include "Teacher.h"
#endif

#include <iostream>
#include <string>
using namespace std;

class Student;
class Accountant : public Employee {
  private:
    vector<Student*> paymentRequests;
  public:
    // Constructors
    Accountant();
    Accountant(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary);
    // Accountant related functions
    bool getStudentPaymentStatus(Student &std);
    void setStudentPendingAmount(vector<Student*> &studentList);
    void processStudentPaymentFlag();
    void showAllStudentPaymentStatus(vector<Student*> studentList);
    void setPaymentRequest(Student &std);
    void updateSalary(vector<Teacher*>t);
    
};