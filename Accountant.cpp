#include "include/Accountant.h"

// class Accountant : public Employee {
//   public:
//     // Constructors
//     Accountant();
//     Accountant(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary);
//     // Accountant related functions
//     bool getStudentPaymentStatus(Student &std);
//     void setStudentPendingAmount(Student &std, double pending_amount);
//     void processStudentPaymentFlag(Student &std);
// };

Accountant::Accountant() : Employee()
{
    designation = "Accountant";
}

Accountant::Accountant(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary) : Employee(v_name, v_address, v_dob, v_email, "Accountant", v_id, v_joinDate, v_salary)
{
}

bool Accountant::getStudentPaymentStatus(Student &std)
{
    if (std.get_paymentClearenceFlag())
        return true;
    else
        return false;
}
// this function will check all students and give the pending amount checking the flags
void Accountant::setStudentPendingAmount(vector<Student *> &studentList)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (!(studentList[i]->get_paymentClearenceFlag()))
        {
            cout << studentList[i]->get_name() << " - " << studentList[i]->get_id() << ": ";
            double pendingAmount;
            cin >> pendingAmount;
            if (pendingAmount == 0)
            {
                studentList[i]->set_paymentClearenceFlag(true);
            }
            studentList[i]->set_pendingAmount(pendingAmount);
        }
    }
}
// this function will check the payment requests and assign payment flags
void Accountant::processStudentPaymentFlag()
{
    for (int i = 0; i < paymentRequests.size(); i++)
    {
        if (paymentRequests[i]->get_pendingAmount() > 0)
            paymentRequests[i]->set_paymentClearenceFlag(false);
        else
            paymentRequests[i]->set_paymentClearenceFlag(true);
    }
}

void Accountant::showAllStudentPaymentStatus(vector<Student *> studentList)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        cout << studentList[i]->get_name() << " - " << studentList[i]->get_id() << ": ";
        if (studentList[i]->get_paymentClearenceFlag())
            cout << "Paid" << endl;
        else
        {
            cout << "Due amount: " << studentList[i]->get_pendingAmount() << endl;
        }
    }
}

void Accountant::setPaymentRequest(Student &std)
{
    Student *request = &std;
    paymentRequests.push_back(request);
}

void Accountant::updateSalary(vector<Teacher *> t)
{
    while (1)
    {
        cout << "==========================================" << endl;
        cout << "-- Teacher List --" << endl;
        for (int i = 0, j = 1; i < t.size(); i++)
        {
            cout << "\t";
            cout << j++ << ": " << t[i]->get_name() << endl;
        }
        int teacherCommand;
        char teacherCommandBuffer;
        cout << "Choose teacher (0 for exit): ";
        cin >> teacherCommandBuffer;
        teacherCommand = teacherCommandBuffer - '0';

        if (!teacherCommand)
        {
            break;
        }

        system("cls");
        cout <<"Set salary amount: ";
        double amount;
        cin>>amount;
        t[teacherCommand-1]->set_salary(amount);
    }
}

// int main(void)
// {
//     date d1 = {1, 2, 3};
//     Student s("sami", "sd", d1, "dasd", "CSE", "2021-2022", 42);
//     Accountant a("sami","ki", d1, "sdf","2123", d1 , 213.2);
//     a.setStudentPendingAmount(s, 0);
//     s.display_information();
// }