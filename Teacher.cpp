#include "include/Teacher.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Teacher::Teacher() : Employee() {
    designation = "Teacher";
    dept = "";
}
Teacher::Teacher(string name, string address, date dob, string email, string id, date joinDate, double salary, string dept) : Employee(name, address, dob, email, "Teacher", id, joinDate, salary) {
    this->dept = dept;
}

// Check course assignment
bool Teacher::isAssigned(CourseCodeFormat courseCode) {
    for (int i = 0; i < assignedCourses.size(); i++) {
        if (assignedCourses[i]->get_courseCode_dept() == courseCode.dept && assignedCourses[i]->get_courseCode_Number() == courseCode.codeNumber)
            return true;
    }
    return false;
}
void Teacher::assignCourse(Course *course) {
    int courseCount = assignedCourses.size();
    if (courseCount >= MAX_COURSE_COUNT) {
        cout<<"Maximum number of course assigned"<<endl;
        return;
    } else if (isAssigned(course->get_courseCode())) {
        return;
    } else {
        Course *temp = course;
        assignedCourses.push_back(temp);
    }
}

void Teacher::takeAttendance(vector<Student*> &studentList) {
    system("CLS");
    int backCommand;
    char backCommandBuffer;
    cout << "Choose Course : " << endl;
    for (int i = 0; i < assignedCourses.size(); i++) {
        cout << "\t" << i + 1 << ": " << assignedCourses[i]->get_title() << endl;
    }
    cout << "Enter sl no: ";
    int command;
    char commandBuffer;
    cin >> commandBuffer;
    command=commandBuffer-'0';
    system("CLS");
    cout << "Enter 1 (Present) / 0 (Absent) : " << endl;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i]->checkRegisteredCourse(assignedCourses[command - 1])) {
            cout << studentList[i]->get_name() << " - " << studentList[i]->get_id() << ": ";
            int flag;
            cin >> flag;
            studentList[i]->addAttendace(assignedCourses[command - 1]->get_courseCode(), flag);
        }
    }
    cout << "Enter 0 for back" << endl;
    cin >> backCommandBuffer;
    backCommand=backCommandBuffer-'0';
    if (backCommand == 0)
        return;
}
// void Teacher::get_ongoing_course_info() {
//     for (int i = 0; i < course_count; i++) {
//         cout << "------Course-" << i + 1 << endl;
//         assigned_courses[i]->showCourseInfo();
//     }
// }
// void Teacher::deassign_course(CourseCodeFormat courseCode) {
//     for (int i = 0; i < course_count; i++) {
//         if (assigned_courses[i]->get_courseCode_dept() == courseCode.dept && assigned_courses[i]->get_courseCode_Number() == courseCode.codeNumber) {
//             delete (assigned_courses[i]);
//             course_count--;
//             break;
//         }
//     }
// }
// int Teacher::get_course_count() {
//     return course_count;
// }

// Display Information
void Teacher::displayInfo() {
    cout << "=============================================" << endl;
    cout << "Teacher Name : " << name << endl;
    cout << "ID : " << id << endl;
    cout << "Address : " << address << endl;
    cout << "DOB : ";
    show_date(dob);
    cout << endl;
    cout << "Email : " << email << endl;
    cout << "Join Date : ";
    show_date(joining_date);
    cout << endl;
    cout << "Salary : " << salary << endl;

    cout << "Assigned Course : " << endl;
    for (int i = 0; i < assignedCourses.size(); i++) {
        cout << "  -- " << assignedCourses[i]->get_title() << endl;
    }
    cout << "=============================================" << endl;
}

string Teacher::get_dept() {
    return dept;
}

// Set marks for
void Teacher::set_quiz1Marks(CourseCodeFormat code, double value, Student &std) {
    std.set_quiz1Marks(code, value);
}
void Teacher::set_quiz2Marks(CourseCodeFormat code, double value, Student &std) {
    std.set_quiz2Marks(code, value);
}
void Teacher::set_quiz3Marks(CourseCodeFormat code, double value, Student &std) {
    std.set_quiz3Marks(code, value);
}
void Teacher::set_quiz4Marks(CourseCodeFormat code, double value, Student &std) {
    std.set_quiz4Marks(code, value);
}
void Teacher::set_midMarks(CourseCodeFormat code, double value, Student &std) {
    std.set_midMarks(code, value);
}
void Teacher::set_finalMarks(CourseCodeFormat code, double value, Student &std) {
    std.set_finalMarks(code, value);
}
void Teacher::setMarks(vector<Student*> studentList){
    system("CLS");
    // int backCommand;
    cout << "Choose Course : " << endl;
    for (int i = 0; i < assignedCourses.size(); i++) {
        cout << "\t" << i + 1 << ": " << assignedCourses[i]->get_title() << endl;
    }
    cout << "Enter sl no: ";
    int command;
    char commandBuffer;
    cin >> commandBuffer;
    command=commandBuffer-'0';
    system("CLS");
    cout<<"Choose exam type: "<<endl;
    cout<< "\t1: Quiz1"<<endl
        << "\t2: Quiz2"<<endl
        << "\t3: Quiz3"<<endl
        << "\t4: Quiz4"<<endl
        << "\t5: Mid"<<endl
        << "\t6: Final"<<endl;
    int examCommand;
    char examCommandBuffer;
    cin>>examCommandBuffer;
    examCommand=examCommandBuffer-'0';
    system("CLS");
    for (int i = 0; i < studentList.size(); i++) {
        // cout<<"Heloo"<<
        if (studentList[i]->checkRegisteredCourse(assignedCourses[command - 1])) {
            cout << studentList[i]->get_name() << " - " << studentList[i]->get_id() << ": ";
            int marks;
            cin >> marks;
            switch (examCommand)
            {
            case 1:
                Teacher::set_quiz1Marks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            case 2:
                Teacher::set_quiz2Marks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            case 3:
                Teacher::set_quiz3Marks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            case 4:
                Teacher::set_quiz4Marks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            case 5:
                Teacher::set_midMarks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            case 6:
                Teacher::set_finalMarks(assignedCourses[command - 1]->get_courseCode(), marks, *studentList[i]);
                break;
            
            default:
                break;
            }
        }
    }

}