#include "Login/Loginsystem.cpp"
#include "include/Accountant.h"
#include "include/Administrator.h"
#include "include/Book.h"
#include "include/Dept_head.h"
#include "include/Librarian.h"
#include "include/Student.h"
#include "include/Teacher.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

// Student login function : when a student is logged in this function will be called with the student pointer, all the course information, all the book information in library and an accountant (assuming one for now)
void studentLogin(Student *s, vector<Course *> c, vector<Book *> b, Accountant &acc) {
    int chooseMenu, totBookNum;
    char loginBuffer;
    while (1) {
        totBookNum = Book::get_total_count();
        system("CLS");
        // cout << totBookNum << endl;
        s->display_information();
        cout
            << "Choose Option" << endl
            << "\t1 : Course Registration" << endl
            << "\t2 : Check Attendance" << endl
            << "\t3 : Check Course Progress" << endl
            << "\t4 : Library Information" << endl
            << "\t0: Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;
        else if (chooseMenu == 1)
            s->courseRegister(c);
        else if (chooseMenu == 2)
            s->checkAttendance();
        else if (chooseMenu == 3) {
            // s->set_quiz1Marks(c[0]->get_courseCode(), 15);
            s->displayCourseResults();
        } else if (chooseMenu == 4) {
            s->libraryAccess(b);
        }
    }
}

// Teacher Login: When a teacher logged in, this function is called with teacher pointer, all the students, all the course information.
void teacherLogin(Teacher *t, vector<Student *> s, vector<Course *> c) {
    int chooseMenu;
    char loginBuffer;
    while (1) {

        system("CLS");
        t->displayInfo();
        cout
            << "Choose Option" << endl
            << "\t1 : Take Attendance" << endl
            << "\t2 : Set Marks" << endl
            << "\t0: Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;
        else if (chooseMenu == 1)
            t->takeAttendance(s);
        else if (chooseMenu == 2) {
            t->setMarks(s);
        }
    }
}
// Librarian Login: When a librarian logged in, this function is called with librarian pointer, all the students, all the books
void librarianLogin(Librarian *l, vector<Book *> &b, vector<Student *> s) {
    int chooseMenu, totBookNum;
    char loginBuffer;
    while (1) {
        totBookNum = Book::get_total_count();
        system("CLS");
        l->display_information();
        cout
            << "\n\nChoose Option - " << endl
            << "\t1: Check Book Borrow Requests and Issued Books" << endl
            << "\t2: View All The Books of The Library" << endl
            << "\t3: Add New Book In The Library" << endl
            << "\t4: Remove Book From The Library" << endl
            << "\t0: Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;
        else if (chooseMenu == 1)
            l->processBorrowReq(b, s);
        else if (chooseMenu == 2)
            l->viewBooks(b);
        else if (chooseMenu == 3)
            l->addBook(b);
        else if (chooseMenu == 4)
            l->removeBook(b);
    }
}

// Dept_head Login: When a Dept_head logged in, this function is called with dept_head pointer, all the students, all the course information.
void dept_headLogin(Dept_head *d, vector<Student *> &s, vector<Course *> &c, vector<Teacher *> &t) {
    int chooseMenu;
    char loginBuffer;
    while (1) {

        system("CLS");
        d->display_information();
        cout
            << "Choose Option" << endl
            << "\t1 : Add new course" << endl
            << "\t2 : Assign course" << endl
            << "\t0 : Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;

        else if (chooseMenu == 1) {
            string s_dept, codeNumber, title;
            double credits;
            cout << "Enter department of the new course: ";
            cin >> s_dept;
            cout << "Enter code number of the course: ";
            cin >> codeNumber;
            cout << "Enter the title: ";
            cin >> title;
            cout << "Enter the number of credits: ";
            cin >> credits;
            Course *temp = d->add_course(s_dept, codeNumber, title, credits);
            c.push_back(temp);
        } else if (chooseMenu == 2) {
            d->assign_course(t, c);
        }
    }
}

// Accountant Login: When a accountant logged in, this function is called with all the students
void accountantLogin(Accountant *a, vector<Student *> &s, vector<Teacher*>&t) {
    int chooseMenu;
    char loginBuffer;
    while (1) {
        system("CLS");
        a->display_information();
        cout
            << "Choose Option" << endl
            << "\t1 : Show all student payment status:" << endl
            << "\t2 : Process student payment status: " << endl
            << "\t3 : Set student due (if any) " << endl
            << "\t4 : Set teacher salary " << endl
            << "\t0: Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;
        else if (chooseMenu == 1) {
            a->showAllStudentPaymentStatus(s);
            getch();
        } else if (chooseMenu == 2)
            a->processStudentPaymentFlag();
        else if (chooseMenu == 3)
            a->setStudentPendingAmount(s);
        else if (chooseMenu == 4)
            a->updateSalary(t);
    }
}

void administratorLogin(Administrator *a, vector<Student *> &s, vector<Teacher *> &t, vector<Librarian *> &l) {
    int chooseMenu;
    char loginBuffer;
    while (1) {
        system("CLS");
        a->display_information();
        cout
            << "Choose Option" << endl
            << "\t1 : Add New Student " << endl
            << "\t2 : Add New Teacher" << endl
            << "\t3 : Add New Librarian" << endl
            << "\t4 : Show All Students" << endl
            << "\t5 : Show All Teachers" << endl
            << "\t6 : Show All Librarians" << endl
            << "\t0: Logout" << endl;
        cout << "\n\n\nEnter Command : ";
        cin >> loginBuffer;
        chooseMenu = loginBuffer - '0';
        if (chooseMenu == 0)
            return;
        else if (chooseMenu == 1) {
            a->addStudent(s);
            getch();
        } else if (chooseMenu == 2) {
            a->addTeacher(t);
            getch();
        } else if (chooseMenu == 3) {
            a->addLibrarian(l);
            getch();
        }
        else if (chooseMenu == 4) {
            a->showStudentsAll(s);
            getch();
        }
        else if (chooseMenu == 5) {
            a->showTeachersAll(t);
            getch();
        }
        else if (chooseMenu == 6) {
            a->showLibAll(l);
            getch();
    }
}
}

void writeStudentID(vector<Student *> &s);
void loadStudent(vector<Student *> &student);

void writeTeacher(vector<Teacher *> &teacher);
void loadTeacher(vector<Teacher *> &teacher);

void writeBooks(vector<Book *> &books);
void loadBooks(vector<Book *> &books);

void writeCourse(vector<Course *> &c);
void loadCourse(vector<Course *> &c);

void writeLibrarian(vector<Librarian *> &lib);
void loadLibraian(vector<Librarian *> &lib);

void writeLibrarian(vector<Librarian *> &lib);
void loadLibraian(vector<Librarian *> &lib);

void writeDeptHead(vector<Dept_head *> &dh);
void loadDeptHead(vector<Dept_head *> &dh);

int main() 
{
    // Courses, Teachers, Students are now manually created objects. But after login and registration process they will be created from registration or  data.
    // Courses
    vector<Course *> c;
    loadCourse(c);
    // c.push_back(new Course(CourseCodeFormat("MATH", "4341"), "Linear Algebra", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4301"), "OOP", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4303"), "Data Structure", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4307"), "Database", 3.0, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4107"), "Structured Programming", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("HUM", "4145"), "Islamiat", 2.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("PHY", "4141"), "Physics", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("MATH", "4141"), "Differential Calculus", 4.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4501"), "Operating System", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4511"), "Computer Networks", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4539"), "Web Programming", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("CSE", "4531"), "Web Security", 3.00, "CSE"));
    // c.push_back(new Course(CourseCodeFormat("MATH", "4321"), "Linear Algebra", 3.00, "EEE"));
    // c.push_back(new Course(CourseCodeFormat("EEE", "4302"), "Power System", 3.00, "EEE"));
    // c.push_back(new Course(CourseCodeFormat("HUM", "4345"), "Science And Islam", 2.00, "EEE"));
    // c.push_back(new Course(CourseCodeFormat("EEE", "4307"), "Digital Electronics", 3.00, "EEE"));

    date d1 = {1, 1, 2000};
    // Students
    vector<Student *> s;
    loadStudent(s);
    // s.push_back(new Student("Eddo", "DHAKA", d1, "eddo@gmail.com", "CSE", "2021", 1));
    // s.push_back(new Student("Radib", "DHAKA", d1, "radibbk@gmail.com", "CSE", "2020", 22));
    // s.push_back(new Student("Dihan", "Chottogram", d1, "diahn@gmail.com", "CSE", "2020", 44));
    // s.push_back(new Student("Shajeed", "Rajshahi", d1, "sah@gmail.com", "CSE", "2019", 42));
    // s.push_back(new Student("Dipto", "Khulna", d1, "eeeav@gmail.com", "EEE", "2020", 1));

    // s[0]->set_paymentClearenceFlag(false);
    // s[0]->set_pending_Payment(100);
    // s[0]->set_semester(1);
    // s[1]->set_semester(3);
    // s[2]->set_semester(3);
    // s[3]->set_semester(5);
    // s[4]->set_semester(3);

    // Teachers
    vector<Teacher *> t;
    loadTeacher(t);
    // t.push_back(new Teacher("Teacher 1", "Rajshahi", d1, "abcd@gmail.com", "24001", d1, 500.01, "CSE"));
    // t.push_back(new Teacher("Teacher 2", "Rajshahi", d1, "rtcd@gmail.com", "24002", d1, 500.02, "CSE"));
    // t.push_back(new Teacher("Teacher 3", "Dhaka", d1, "efgh@gmail.com", "22001", d1, 1500.01, "EEE"));

    // // Manually assigned courses to teacher, But this function will be called from Department Head object.
    // t[0]->assignCourse(c[0]);
    // t[0]->assignCourse(c[1]);
    // t[0]->assignCourse(c[2]);
    // t[0]->assignCourse(c[3]);
    // t[0]->assignCourse(c[4]);
    // t[0]->assignCourse(c[5]);
    // t[0]->assignCourse(c[6]);
    // t[0]->assignCourse(c[7]);
    // t[0]->assignCourse(c[8]);
    // t[0]->assignCourse(c[9]);
    // t[1]->assignCourse(c[10]);
    // t[1]->assignCourse(c[11]);
    // t[2]->assignCourse(c[12]);
    // t[2]->assignCourse(c[13]);
    // t[2]->assignCourse(c[14]);
    // t[2]->assignCourse(c[15]);
    // Books All the books information will be loaded from a data.
    vector<Book *> b;
    loadBooks(b);
    // b.push_back(new Book("Book 1", "Author 1", "Publisher 1", "Genre 1", 10, 101));
    // b.push_back(new Book("Book 2", "Author 2", "Publisher 2", "Genre 2", 10, 102));
    // b.push_back(new Book("Book 3", "Author 3", "Publisher 3", "Genre 3", 10, 103));
    // b.push_back(new Book("Book 4", "Author 4", "Publisher 4", "Genre 4", 15, 104));

    // librarian
    vector<Librarian *> l;
    loadLibraian(l);
    // l.push_back(new Librarian("Dihan mama", "Gazipur", d1, "dihanmama@gmail.com", "31001", d1, 20000));
    // l.push_back(new Librarian("Abdullah", "Shirajganj", d1, "abdul@gmail.com", "31002", d1, 20000));

    // accountant
    Accountant acc("Hasan Ali", "Mirpur", d1, "hasanalia@gmail.com", "51001", d1, 100000);

    // dept_head
    vector<Dept_head *> dh;
    loadDeptHead(dh);
    // dh.push_back(new Dept_head("CSE Head", "Khulna", d1, "abcd@gmail.com", "41001", d1, 90000, "CSE"));
    // dh.push_back(new Dept_head("EEE Head", "Khulna", d1, "abcd@gmail.com", "41002", d1, 90000, "EEE"));
    //dh.push_back(new Dept_head("MPE Head", "Dhaka", d1, "abcde@gmail.com", "41003", d1, 90000, "MPE"));
    //dh.push_back(new Dept_head("CEE Head", "Rajshahi", d1, "abcdf@gmail.com", "41005", d1, 90000, "CEE"));
    //dh.push_back(new Dept_head("BTM Head", "Dhaka", d1, "abcdg@gmail.com", "41006", d1, 90000, "BTM"));

    // administrator
    Administrator admin("Admin", "Dhaka", d1, "admin@iut-dhaka.edu", "61001", d1, 25000.0);

    int chooseLogin;
    char loginBuffer;
    string userName;
    string password;
    string userId;
    bool check;

    // for the login system we can take student id/ teacher id etc to identify that person and login into that profile.
    // but currently login with the real name and a hardcoded password. hardcode format in txt file : usernamepassword
    while (1) {
        system("CLS");

        printf("\n\n\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t\xba                                                                           \xba\n");
        printf("\t\xba                  >>>  UNIVERSITY INFORMATION SYSTEM  <<<                  \xba\n");
        printf("\t\xba                                                                           \xba\n");
        printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");
        cout << "\n\n\t\t\t--------------- Login As ---------------\n\n"<< endl;

        printf("\n\t\t\t     1. STUDENT\n");
        printf("\n\t\t\t     2. TEACHER\n");
        printf("\n\t\t\t     3. LIBRARIAN\n");
        printf("\n\t\t\t     4. DEPARTMENT HEAD\n");
        printf("\n\t\t\t     5. ACCOUNTANT\n");
        printf("\n\t\t\t     6. ADMINISTRATOR\n");
        printf("\n\t\t\t     0. EXIT\n\n");

        cout << "\n\n\tEnter Command : ";
        cin >> loginBuffer;
        chooseLogin = loginBuffer - '0'; // to avoid the crashing of the program
        if (chooseLogin == 0)
            break;
        else if (chooseLogin == 1) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            for (auto &x : s) {
                userId = x->get_id();
                if (userName == userId)
                    studentLogin(x, c, b, acc);
            }
        } else if (chooseLogin == 2) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            for (auto &x : t) {
                userId = x->get_id();
                if (userName == userId)
                    teacherLogin(x, s, c);
            }
        } else if (chooseLogin == 3) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            for (auto &x : l) {
                userId = x->get_id();
                if (userName == userId)
                    librarianLogin(x, b, s);
            }
        } else if (chooseLogin == 4) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            for (auto &x : dh) {
                userId = x->get_id();
                if (userName == userId)
                    dept_headLogin(x, s, c, t);
            }
        } else if (chooseLogin == 5) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            accountantLogin(&acc, s, t);
        } else if (chooseLogin == 6) {
            cout << "\n\n\n--- Enter Username : ";
            fflush(stdin);
            getline(cin, userName);
            cout << "\n\n--- Enter Password : ";
            fflush(stdin);
            getline(cin, password);
            check = loginScreen(userName, password, chooseLogin);
            if (!check)
                continue;
            administratorLogin(&admin, s, t, l);
        }
    }
    writeCourse(c);
    writeTeacher(t);
    writeStudentID(s);
    writeBooks(b);
    writeDeptHead(dh);
    writeLibrarian(l);
    return 0;
}

void writeStudentID(vector<Student *> &s) {
    ofstream outstdID;
    string sid;
    int temp;
    outstdID.open("data/student_ID.txt", ios::out);
    if (outstdID.is_open()) {
        outstdID << s.size() << endl;
        for (int i = 0; i < s.size(); i++) {
            sid = s[i]->get_id();
            outstdID << sid << endl;
            ofstream outstdInfo;
            sid = "data/studentInfo/" + sid + ".txt";
            outstdInfo.open(sid, ios::out);
            if (outstdInfo.is_open()) {
                outstdInfo << s[i]->get_name() << endl;
                outstdInfo << s[i]->get_dob_d() << endl;
                outstdInfo << s[i]->get_dob_m() << endl;
                outstdInfo << s[i]->get_dob_y() << endl;
                outstdInfo << s[i]->get_email() << endl;
                outstdInfo << s[i]->get_address() << endl;
                outstdInfo << s[i]->get_dept() << endl;
                outstdInfo << s[i]->get_semester() << endl;
                outstdInfo << s[i]->get_academic_year() << endl;
                outstdInfo << s[i]->get_paymentClearenceFlag() << endl;
                outstdInfo << s[i]->get_pendingAmount() << endl;
                outstdInfo << s[i]->get_course_count() << endl;
                temp = s[i]->get_course_count();
                for (int j = 0; j < temp; j++) {

                    outstdInfo << s[i]->courseTaken[j]->get_courseDept() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_title() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_courseCode_dept() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_courseCode_Number() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_credit() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_attendace() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_classCount() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_presentCount() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_quiz1Marks() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_quiz2Marks() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_quiz3Marks() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_quiz4Marks() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_midMarks() << endl;
                    outstdInfo << s[i]->courseTaken[j]->get_finalMarks() << endl;
                }

                int bookFlag = s[i]->booksTaken.size();
                outstdInfo << bookFlag << endl;
                for (int j = 0; j < bookFlag; j++) {
                    outstdInfo << s[i]->booksTaken[j]->get_title() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_author() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_publisher() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_genre() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_total_copies() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_available_copies() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_registration_number() << endl;
                    outstdInfo << s[i]->booksTaken[j]->get_issued_by() << endl;

                    date d1 = s[i]->booksTaken[j]->get_borrowDate();
                    outstdInfo << d1.day << endl;
                    outstdInfo << d1.month << endl;
                    outstdInfo << d1.year << endl;
                    d1 = s[i]->booksTaken[j]->get_returnDate();
                    outstdInfo << d1.day << endl;
                    outstdInfo << d1.month << endl;
                    outstdInfo << d1.year << endl;
                }
            }
        }
    }
}

void loadStudent(vector<Student *> &student) {
    ifstream studentObj("data/student_ID.txt", ios::in);
    int totalStudent;
    studentObj >> totalStudent;
    // cout << totalStudent << endl;
    for (int i = 0; i < totalStudent; i++) {
        string id;
        studentObj >> id;
        string fileUrl = "data/studentInfo/" + id + ".txt";
        ifstream indStudent(fileUrl, ios::in);
        string name;
        // Name
        indStudent >> name;
        // cout << name << endl;
        //  DOB
        int dd, mm, yy;
        indStudent >> dd;
        indStudent >> mm;
        indStudent >> yy;
        date d1 = {dd, mm, yy};
        // cout << dd << " " << yy << endl;
        //  Email
        string email;
        indStudent >> email;
        // cout << email << endl;
        //  Address
        string address;
        indStudent >> address;
        // cout << address << endl;
        //  Dept
        string dept;
        indStudent >> dept;
        // cout << dept << endl;
        //  Semester
        int semester;
        indStudent >> semester;
        // cout << semester << endl;
        //  academic year
        string academic_year;
        indStudent >> academic_year;
        // cout << academic_year << endl;

        // Payment Status
        bool flag;
        indStudent >> flag;
        // cout << flag << endl;
        double pending;
        indStudent >> pending;
        // cout << pending << endl;

        Student *temp = new Student(id, name, d1, email, address, dept, semester, academic_year, flag, pending);

        // RegisteredCourse
        int totalCourse;
        indStudent >> totalCourse;
        // cout << totalCourse << endl;

        for (int t = 0; t < totalCourse; t++) {
            string CourseDept;
            indStudent >> CourseDept;
            // cout << CourseDept << endl;
            string title;
            // indStudent >> title;
            indStudent.ignore();
            getline(indStudent, title, '\n');
            // cout << title << endl;
            string codeDept;
            string codeNumber;
            indStudent >> codeDept >> codeNumber;
            // cout << codeDept << endl;
            // cout << codeNumber << endl;
            CourseCodeFormat f1 = {codeDept, codeNumber};
            double credit;
            indStudent >> credit;
            // cout << credit << endl;
            double percentage;
            indStudent >> percentage;
            // cout << percentage << endl;
            int classCount, presentCount;
            indStudent >> classCount >> presentCount;
            // cout << classCount << " " << presentCount << endl;
            RegisteredCourse *rtemp = new RegisteredCourse(CourseDept, title, f1, credit, percentage, classCount, presentCount);

            double quiz1, quiz2, quiz3, quiz4, mid, final;
            indStudent >> quiz1;
            indStudent >> quiz2 >> quiz3 >> quiz4 >> mid;
            indStudent >> final;
            // cout << final << endl;
            rtemp->set_quiz1Marks(quiz1);
            rtemp->set_quiz2Marks(quiz2);
            rtemp->set_quiz3Marks(quiz3);
            rtemp->set_quiz4Marks(quiz4);
            rtemp->set_midMarks(mid);
            rtemp->set_finalMarks(final);
            temp->setRegisteredCourse(rtemp);
        }

        // Books
        int booksFlag;
        // indStudent.ignore();
        indStudent >>
            booksFlag;
        // cout << "flag " << booksFlag << endl;
        if (booksFlag) {
            for (int i = 0; i < booksFlag; i++) {
                string title;
                indStudent.ignore();
                getline(indStudent, title, '\n');
                // cout << title << endl;
                string author;

                getline(indStudent, author, '\n');
                // cout << author << endl;
                string publisher;

                getline(indStudent, publisher, '\n');
                // cout << publisher << endl;
                string genre;
                getline(indStudent, genre, '\n');
                // cout << genre << endl;
                int totalCopies;
                indStudent >> totalCopies;
                // cout << totalCopies << endl;
                int availableCopies;
                indStudent >> availableCopies;
                // cout << availableCopies << endl;
                int registrationNumber;
                indStudent >> registrationNumber;
                // cout << registrationNumber << endl;

                string issued_by;
                indStudent.ignore();
                getline(indStudent, issued_by, '\n');
                // cout << issued_by << endl;
                int borrowDD, borrowMM, borrowYY;
                indStudent >> borrowDD >> borrowMM >> borrowYY;
                date borrowDate = {borrowDD, borrowMM, borrowYY};

                int returnDD, returnMM, returnYY;
                indStudent >> returnDD >> returnMM >> returnYY;
                date returnDate = {returnDD, returnMM, returnYY};

                // BorrowedBooks(string title,
                //               string author,
                //               string publisher,
                //               string genre,
                //               int totalCopies,
                //               int availableCopies,
                //               int registrationNumber, string issued_by,
                //               date borrowDate,
                //               date returnDate);
                BorrowedBooks *btemp = new BorrowedBooks(title,
                                                         author,
                                                         publisher,
                                                         genre,
                                                         totalCopies,
                                                         availableCopies,
                                                         registrationNumber, issued_by,
                                                         borrowDate,
                                                         returnDate);
                temp->set_booksTaken(btemp);
            }
        }
        student.push_back(temp);
    }
}

void writeTeacher(vector<Teacher *> &teacher) {
    ofstream teacherInfo("./data/teacher_id.txt");
    teacherInfo << teacher.size() << endl;
    for (int i = 0; i < teacher.size(); i++) {
        teacherInfo << teacher[i]->get_id() << endl;
        string url = "./data/teacherInfo/" + teacher[i]->get_id() + ".txt";
        ofstream indTeacher(url);
        // string designation;
        indTeacher << teacher[i]->get_name() << endl;
        indTeacher << teacher[i]->get_dob_d() << endl;
        indTeacher << teacher[i]->get_dob_m() << endl;
        indTeacher << teacher[i]->get_dob_y() << endl;
        indTeacher << teacher[i]->get_email() << endl;
        indTeacher << teacher[i]->get_address() << endl;
        indTeacher << teacher[i]->get_designation() << endl;
        date d1 = teacher[i]->get_joiningDate();
        indTeacher << d1.day << endl;
        indTeacher << d1.month << endl;
        indTeacher << d1.year << endl;
        indTeacher << teacher[i]->get_salary() << endl;
        indTeacher << teacher[i]->get_dept() << endl;
        indTeacher
            << teacher[i]->assignedCourses.size() << endl;
        for (int j = 0; j < teacher[i]->assignedCourses.size(); j++) {
            indTeacher << teacher[i]->assignedCourses[j]->get_courseDept() << endl;
            indTeacher << teacher[i]->assignedCourses[j]->get_title() << endl;
            indTeacher << teacher[i]->assignedCourses[j]->get_courseCode_dept() << endl;
            indTeacher << teacher[i]->assignedCourses[j]->get_courseCode_Number() << endl;
            indTeacher << teacher[i]->assignedCourses[j]->get_credit() << endl;
        }
    }
}
void loadTeacher(vector<Teacher *> &teacher) {
    ifstream teacherInfo("./data/teacher_id.txt");
    int teacherSize;
    teacherInfo >> teacherSize;
    for (int i = 0; i < teacherSize; i++) {
        string id;
        teacherInfo >> id;
        string url = "./data/teacherInfo/" + id + ".txt";
        ifstream indTeacher(url);
        // string designation;
        string name;
        getline(indTeacher, name, '\n');
        int dd, mm, yy;
        indTeacher >> dd >> mm >> yy;
        date d1 = {dd, mm, yy};
        string email;
        indTeacher >> email;
        string address;
        indTeacher >> address;
        string designation;
        indTeacher >> designation;
        indTeacher >> dd >> mm >> yy;
        date jd1 = {dd, mm, yy};
        double salary;
        indTeacher >> salary;
        string dept;
        indTeacher >> dept;
        // indTeacher.ignore(numeric_limits<streamsize>::max(),'\n');
        Teacher *temp = new Teacher(name, address, d1, email, id, jd1, salary, dept);
        int assignedCourse;
        indTeacher >> assignedCourse;

        for (int j = 0; j < assignedCourse; j++) {
            string offeredDept;
            indTeacher >> offeredDept;
            string title;
            indTeacher.ignore();
            getline(indTeacher, title, '\n');
            string courseDept;
            string CourseNumber;
            indTeacher >> courseDept;
            indTeacher >> CourseNumber;
            CourseCodeFormat courseCode = {courseDept, CourseNumber};

            double credits;
            indTeacher >> credits;
            // indTeacher.ignore(numeric_limits<streamsize>::max(),'\n');
            Course *tempC = new Course(courseCode, title, credits, offeredDept);
            temp->assignedCourses.push_back(tempC);
        }
        teacher.push_back(temp);
    }
}

void writeBooks(vector<Book *> &books) {
    ofstream bookInfo("./data/bookList.txt");
    bookInfo << books.size()
             << endl;
    for (int i = 0; i < books.size(); i++) {
        bookInfo << books[i]->get_registration_number() << endl;
        int regNo = books[i]->get_registration_number();
        string registrationNo = to_string(regNo);
        string url = "./data/bookInfo/" + registrationNo + ".txt";
        ofstream indBook(url);
        indBook << books[i]->get_title() << endl;
        indBook << books[i]->get_author() << endl;
        indBook << books[i]->get_publisher() << endl;
        indBook << books[i]->get_genre() << endl;
        indBook << books[i]->get_total_copies() << endl;
        indBook << books[i]->get_available_copies() << endl;
    }
}
void loadBooks(vector<Book *> &books) {
    ifstream bookInfo("./data/bookList.txt");
    int bookSize;
    bookInfo >> bookSize;
    for (int i = 0; i < bookSize; i++) {
        int regNo;
        bookInfo >> regNo;
        string registrationNo = to_string(regNo);

        string url = "./data/bookInfo/" + registrationNo + ".txt";
        ifstream indBook(url);
        string title;
        getline(indBook, title);
        string author;
        getline(indBook, author);
        string publisher;
        getline(indBook, publisher);
        string genre;
        getline(indBook, genre);
        int totalCopies;
        indBook >> totalCopies;
        int availableCopies;
        indBook >> availableCopies;
        int registrationNumber;
        indBook >> registrationNumber;

        Book *temp = new Book(title, author, publisher, genre, totalCopies, availableCopies, regNo);
        books.push_back(temp);
    }
}

void writeCourse(vector<Course *> &c) {
    ofstream courseInfo("./data/courseInfo/courses.txt");
    courseInfo << c.size() << endl;
    for (int i = 0; i < c.size(); i++) {
        courseInfo << c[i]->get_courseCode_dept() << endl;
        courseInfo << c[i]->get_courseCode_Number() << endl;
        courseInfo << c[i]->get_title() << endl;
        courseInfo << c[i]->get_credit() << endl;
        courseInfo << c[i]->get_offeredDept() << endl;
    }
}

void loadCourse(vector<Course *> &c) {
    ifstream courseInfo("./data/courseInfo/courses.txt");
    int courseSize;
    courseInfo >> courseSize;
    for (int i = 0; i < courseSize; i++) {
        CourseCodeFormat cf;
        courseInfo >> cf.dept;
        courseInfo >> cf.codeNumber;
        string title;
        courseInfo.ignore();
        getline(courseInfo, title);
        double credit;
        courseInfo >> credit;
        string offered_dept;
        courseInfo >> offered_dept;
        courseInfo.ignore();
        Course *temp = new Course(cf, title, credit, offered_dept);
        c.push_back(temp);
    }
}

void writeLibrarian(vector<Librarian *> &lib) {
    ofstream libInfo("./data/librarian_id.txt");
    libInfo << lib.size() << endl;
    for (int i = 0; i < lib.size(); i++) {
        libInfo << lib[i]->get_id() << endl;
        string url = "./data/libInfo/" + lib[i]->get_id() + ".txt";
        ofstream indlib(url);
        // string designation;
        indlib << lib[i]->get_name() << endl;
        indlib << lib[i]->get_address() << endl;
        indlib << lib[i]->get_dob_d() << endl;
        indlib << lib[i]->get_dob_m() << endl;
        indlib << lib[i]->get_dob_y() << endl;
        indlib << lib[i]->get_email() << endl;
        indlib << lib[i]->get_designation() << endl;
        date d1 = lib[i]->get_joiningDate();
        indlib << d1.day << endl;
        indlib << d1.month << endl;
        indlib << d1.year << endl;
        indlib << lib[i]->get_salary() << endl;
    }
}

void loadLibraian(vector<Librarian *> &lib) {
    ifstream libInfo("./data/librarian_id.txt");
    int libSize;
    libInfo >> libSize;
    for (int i = 0; i < libSize; i++) {
        string id;
        libInfo >> id;
        string url = "./data/libInfo/" + id + ".txt";
        ifstream indlib(url);
        // string designation;
        string name;
        getline(indlib, name, '\n');
        string address;
        indlib >> address;
        int dd, mm, yy;
        indlib >> dd >> mm >> yy;
        date d1 = {dd, mm, yy};
        string email;
        indlib >> email;
        string designation;
        indlib >> designation;
        indlib >> dd >> mm >> yy;
        date jd1 = {dd, mm, yy};
        double salary;
        indlib >> salary;
        // indlib.ignore(numeric_limits<streamsize>::max(),'\n');
        Librarian *temp = new Librarian(name, address, d1, email, id, jd1, salary);
        lib.push_back(temp);
    }
}

void writeDeptHead(vector<Dept_head *> &dh) {
    ofstream teacherInfo("./data/deptHead.txt");
    teacherInfo << dh.size() << endl;
    for (int i = 0; i < dh.size(); i++) {
        teacherInfo << dh[i]->get_id() << endl;
        string url = "./data/deptHeadInfo/" + dh[i]->get_id() + ".txt";
        ofstream indTeacher(url);
        // string designation;
        indTeacher << dh[i]->get_name() << endl;
        indTeacher << dh[i]->get_dob_d() << endl;
        indTeacher << dh[i]->get_dob_m() << endl;
        indTeacher << dh[i]->get_dob_y() << endl;
        indTeacher << dh[i]->get_email() << endl;
        indTeacher << dh[i]->get_address() << endl;
        indTeacher << dh[i]->get_designation() << endl;
        date d1 = dh[i]->get_joiningDate();
        indTeacher << d1.day << endl;
        indTeacher << d1.month << endl;
        indTeacher << d1.year << endl;
        indTeacher << dh[i]->get_salary() << endl;
        indTeacher << dh[i]->get_dept() << endl;
    }
}
void loadDeptHead(vector<Dept_head *> &dh) {
    ifstream teacherInfo("./data/deptHead.txt");
    int teacherSize;
    teacherInfo >> teacherSize;
    for (int i = 0; i < teacherSize; i++) {
        string id;
        teacherInfo >> id;
        string url = "./data/deptHeadInfo/" + id + ".txt";
        ifstream indTeacher(url);
        // string designation;
        string name;
        getline(indTeacher, name, '\n');
        int dd, mm, yy;
        indTeacher >> dd >> mm >> yy;
        date d1 = {dd, mm, yy};
        string email;
        indTeacher >> email;
        string address;
        indTeacher >> address;
        string designation;
        indTeacher >> designation;
        indTeacher >> dd >> mm >> yy;
        date jd1 = {dd, mm, yy};
        double salary;
        indTeacher >> salary;
        string dept;
        indTeacher >> dept;
        // indTeacher.ignore(numeric_limits<streamsize>::max(),'\n');
        Dept_head *temp = new Dept_head(name, address, d1, email, id, jd1, salary, dept);

        dh.push_back(temp);
    }
}
