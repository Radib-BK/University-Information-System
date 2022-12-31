#pragma once

#include "Employee.h"
#include "Student.h"
#include "Teacher.h"
#include "Librarian.h"
#include <stdio.h>
#include <fstream>

class Administrator : public Employee
{
public:
    Administrator();
    Administrator(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary);
    void addStudent(vector<Student*>& s);
    void addTeacher(vector<Teacher*>& t);
    void addLibrarian(vector<Librarian*>& l);
    void showStudentsAll(vector <Student*> s);
    void showTeachersAll(vector<Teacher*> t);
    void showLibAll(vector<Librarian*> l);
};

