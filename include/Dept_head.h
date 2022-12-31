#include "Course.h"
#include "Teacher.h"
#include <iostream>
#include <string>
using namespace std;

class Dept_head : public Teacher {
  public:
    // constructors
    Dept_head();
    Dept_head(string name, string address, date dob, string email, string id, date joinDate, double salary, string dept);

    // Dept_head is able to add new courses to his own department
    Course *add_course(string s_dept, string codeNumber, string title, double credits /*, string offeredDept*/);
    // this function will take the list of teachers as input and assign course related to
    void assign_course(vector<Teacher *> t, vector<Course *> c);
};