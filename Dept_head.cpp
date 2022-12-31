#include "include/Dept_head.h"

#include <iostream>
#include <string>
using namespace std;

// class Dept_head : public Teacher {
//   public:
//     // constructors
//     Dept_head();
//     Dept_head(string name, string address, date dob, string email, string id, date joinDate, double salary, string dept);

//     // Dept_head is able to add new courses to his own department
//     Course *add_course(string s_dept, string codeNumber, string title, double credits /*, string offeredDept*/);
// };

Dept_head::Dept_head() : Teacher() {
}

Dept_head::Dept_head(string name, string address, date dob, string email, string id, date joinDate, double salary, string dept) : Teacher(name, address, dob, email, id, joinDate, salary, dept) {
}

Course *Dept_head::add_course(string s_dept, string codeNumber, string title, double credits /*, string offeredDept*/) {
    Course *new_course = new Course(CourseCodeFormat(s_dept, codeNumber), title, credits, this->dept);
    return new_course;
}
// this takes list of teachers and courses and assigns them
void Dept_head::assign_course(vector<Teacher *> t, vector<Course *> c) {
    string hdept, tdept;
    while (1) {
        cout << "==========================================" << endl;
        cout << "-- Teacher List --" << endl;
        for (int i = 0, j = 1; i < t.size(); i++) {
            hdept = get_dept();
            tdept = t[i]->get_dept();
            if (tdept == hdept) {
                cout << "\t";
                cout << j++ << ": " << t[i]->get_name() << endl;
            }
        }
        int teacherCommand;
        char teacherCommandBuffer;
        cout << "Choose teacher (0 for exit): ";
        cin >> teacherCommandBuffer;
        teacherCommand = teacherCommandBuffer - '0';

        if (!teacherCommand) {
            break;
        }

        system("cls");
        int command;
        cout << "==========================================" << endl;
        cout << "-- Course List --" << endl;
        // This loop listing all the courses those are matched with student semester and dept and also keeps them in a temporary vector.
        for (int i = 0, j = 1; i < c.size(); i++) {
            hdept = get_dept();
            tdept = c[i]->get_courseCode_dept();
            if (tdept == hdept) {
                cout << "\t";
                cout << j++ << ": " << c[i]->get_courseCode_dept() << " " << c[i]->get_courseCode_Number() << endl;
            }
        }
        // This loop selecting the courses.
        while (1) {
            cout << "Choose Course (0 for exit) : ";
            cin >> command;
            if (command == 0)
                break;
            if (t[teacherCommand - 1]->isAssigned(c[command - 1]->get_courseCode())) {
                cout << "Already Assigned" << endl;
                continue;
            }
            t[teacherCommand - 1]->assignCourse(c[command - 1]);
        }
    }
}
