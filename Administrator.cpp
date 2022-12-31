#include "include/Administrator.h"

Administrator::Administrator() : Employee()
{
    designation = "Administrator";
}
Administrator::Administrator(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary)
{
    this->name = v_name;
    this->address = v_address;
    this->dob = v_dob;
    this->email = v_email;
    this->id = v_id;
    this->joining_date = v_joinDate;
    this->salary = v_salary;
    this->designation = "Administrator";
}

void Administrator::addStudent(vector<Student*>& s)
{
    system("cls");
    string sname, saddress, semail, sdept, sacyear,spass;
    int serial,sem;
    double due = 0.0;
    bool flag = true;
    date d;
    char pay;
    Student *std;
    cout << "Please Enter Student Info -"<<endl;
    cout << "Name\t\t: ";
    fflush(stdin);
    getline(cin, sname);
    cout << "Password\t: ";
    fflush(stdin);
    getline(cin, spass);
    cout << "Address\t\t: ";
    fflush(stdin);
    getline(cin, saddress);
    cout << "Email\t\t: ";
    fflush(stdin);
    getline(cin, semail);
    cout << "Date of Birth (day/month/year) : ";
    scanf(" %d/%d/%d",&d.day,&d.month,&d.year);
    fflush(stdin);
    cout<<"Department\t: ";
    getline(cin, sdept);
    cout << "Academic Year : ";
    fflush(stdin);
    getline(cin, sacyear);
    cout << "Serial on Dept : ";
    cin >> serial;
    cout << "Semester\t: ";
    cin >> sem;
    cout <<"\nPayment Clear? (y/n) : ";
    cin >> pay;
    if(pay == 'n'||pay == 'N')
        {
            flag = false;
            cout << "\nDue Amount\t: ";
            cin >> due;
        }

    std = new Student(sname, saddress, d, semail, sdept, sacyear, serial);
    std->set_semester(sem);
    std->set_paymentClearenceFlag(flag);
    std->set_pendingAmount(due);
    
    fstream sFile;
    sFile.open("Login/studentLogin.txt", ios::app);
    if (sFile.is_open())
    {
        sFile << endl << std->get_id() << spass;
        sFile.close();
    }
    system("cls");
    std->display_information();
    cout << "\n\n\nPRESS ENTER TO CONTINUE" << endl;
    s.push_back(std);
}

void Administrator::addTeacher(vector<Teacher*>& t)
{
    system("cls");
    string tname, taddress, temail, tid, tdept, tpass;
    double tsalary = 0.0;
    date dob, jd;
    Teacher *tch;
    cout << "Please Enter Teacher Info -"<<endl;
    cout << "Name\t\t: ";
    fflush(stdin);
    getline(cin, tname);
    cout << "Password\t: ";
    fflush(stdin);
    getline(cin, tpass);
    cout << "Address\t\t: ";
    fflush(stdin);
    getline(cin, taddress);
    cout << "Email\t\t: ";
    fflush(stdin);
    getline(cin, temail);
    cout << "Date of Birth (day/month/year) : ";
    scanf(" %d/%d/%d",&dob.day,&dob.month,&dob.year);
    fflush(stdin);
    cout << "Given ID\t :";
    cin >> tid;
    cout<<"Department\t: ";
    fflush(stdin);
    cout<<"Salary\t\t: ";
    cin >> tsalary;
    getline(cin, tdept);
    cout << "Joining Date\t: ";
    scanf(" %d/%d/%d",&jd.day,&jd.month,&jd.year);

    tch = new Teacher(tname,taddress,dob,temail,tid,jd,tsalary,tdept);
    
    fstream tFile;
    tFile.open("Login/teacherLogin.txt", ios::app);
    if (tFile.is_open())
    {
        tFile << endl << tid << tpass;
        tFile.close();
    }
    system("cls");
    tch->display_information();
    cout << "\n\n\nPRESS ENTER TO CONTINUE" << endl;
    t.push_back(tch);
}

void Administrator::addLibrarian(vector<Librarian*>& l)
{
    system("cls");
    string lname, laddress, lemail, lid, lpass;
    double lsalary = 0.0;
    date dob, jd;
    Librarian *lib;
    cout << "Please Enter Librarian Info -"<<endl;
    cout << "Name\t\t: ";
    fflush(stdin);
    getline(cin, lname);
    cout << "Password\t: ";
    fflush(stdin);
    getline(cin, lpass);
    cout << "Address\t\t: ";
    fflush(stdin);
    getline(cin, laddress);
    cout << "Email\t\t: ";
    fflush(stdin);
    getline(cin, lemail);
    cout << "Date of Birth (day/month/year) : ";
    scanf(" %d/%d/%d",&dob.day,&dob.month,&dob.year);
    fflush(stdin);
    cout << "Given ID\t :";
    cin >> lid;
    cout << "Joining Date\t: ";
    scanf(" %d/%d/%d",&jd.day,&jd.month,&jd.year);
    cout<< "Salary\t\t: ";
    cin >> lsalary;

    lib = new Librarian(lname,laddress,dob,lemail,lid,jd,lsalary);
    
    fstream lFile;
    lFile.open("Login/librarianLogin.txt", ios::app);
    if (lFile.is_open())
    {
        lFile << endl << lid << lpass;
        lFile.close();
    }
    system("cls");
    lib->display_information();
    cout << "\n\n\nPRESS ENTER TO CONTINUE" << endl;
    l.push_back(lib);
}

void Administrator:: showStudentsAll(vector <Student*> s)
{
    for (auto& x : s)
    {
        x->display_information();
    }
    
}

void Administrator:: showTeachersAll(vector <Teacher*> t)
{
    for (auto& x : t)
    {
        x->display_information();
    }
    
}

void Administrator:: showLibAll(vector <Librarian*> l)
{
    for (auto& x : l)
    {
        x->display_information();
    }
    
}