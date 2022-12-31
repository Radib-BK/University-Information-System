#include "include/Librarian.h"
#include<conio.h>

Librarian::Librarian() : Employee()
{
    designation = "Librarian";
}
Librarian::Librarian(string v_name, string v_address, date v_dob, string v_email, string v_id, date v_joinDate, double v_salary) : Employee(v_name, v_address, v_dob, v_email, "Librarian", v_id, v_joinDate, v_salary) {}

void Librarian::processBorrowReq(vector<Book *> b, vector<Student*> std)
{
    system("cls");
    for (int i = 0; i < std[i]->get_std_count(); i++)
    {
        if (std[i]->booksTaken.size())
        {
            cout << "Pending Requests for Student ID : " << std[i]->get_id() << endl;
            int cmd;
            int reg;
            int count, size, flag = 0;
            count = 0;
            size = std[i]->booksTaken.size();
            while (size--)
            {
                reg = std[i]->booksTaken[count]->get_registration_number();
                for (int j = 0; j < b.size(); j++)
                {
                    if (b[j]->get_registration_number() == reg)
                    {
                        flag = 1;
                        b[j]->display_book();
                    }
                }
                if (flag == 0)
                {
                    cout << std[i]->booksTaken[count]->get_title() << endl;
                    cout << "\n\nThis Book Is Not In The Library Anymore\n"<<endl;
                    std[i]->booksTaken.erase(std[i]->booksTaken.begin() + count);
                    getch();
                    continue;
                }
                
                // std[i]->booksTaken[count]->display_book();
                if (std[i]->booksTaken[count]->get_borrow_grant_status()) // if already granted req and need to recheck return date
                {
                    cout << endl;
                    cout << "This Book Was Issued By : " << std[i]->booksTaken[count]->get_issued_by() << endl;
                    cout << "Book Borrow Date : ";
                    show_date(std[i]->booksTaken[count]->get_borrowDate());
                    cout << endl;
                    cout << "Book Return Date : ";
                    show_date(std[i]->booksTaken[count]->get_returnDate());
                    cout << endl;
                    cout << "\n\n\n-- Let Student Keep The Book ?? ('1' for yes | '0' for no) ---  ";
                }
                else
                    cout << "\n\n\n-- Grant Borrow Request ?? ('1' for yes | '0' for no) ---  ";
                fflush(stdin);
                cin >> cmd;
                if (cmd)
                {
                    // reg = std[i]->booksTaken[count]->get_registration_number();
                    for (int j = 0; j < b.size(); j++)
                    {
                        if (b[j]->get_registration_number() == reg && std[i]->booksTaken[count]->get_borrow_grant_status() != true)
                            b[j]->decrease_available_copies(); // Decreasing available book count
                    }
                    if (!std[i]->booksTaken[count]->get_borrow_grant_status())
                    {
                        string l_name;
                        l_name = get_name();
                        std[i]->booksTaken[count]->set_issued_by(l_name);
                    } 
                    std[i]->booksTaken[count]->set_borrow_grant_status(true);
                    count++;
                }
                else
                {
                    if (std[i]->booksTaken[count]->get_borrow_grant_status() == true)
                    {
                        for (int j = 0; j < b.size(); j++)
                        {
                            if (b[j]->get_registration_number() == reg)
                                b[j]->increase_available_copies();          //if an issued book is returned then total copy of that book will increase
                        }
                    }
                    std[i]->booksTaken.erase(std[i]->booksTaken.begin() + count);

                } // erases the denied requests but keeps the accepted requests in the booksTaken vector.
                cout << endl << endl;
            }
            system("CLS");
        }
    }
}

void Librarian::addBook(vector<Book *> &b)
{
    system("cls");
    string bookName, authorName, publisherName, genreName;
    int totcpy, regno;
    Book *bk;
    cout << "Enter the name of the Book : ";
    fflush(stdin);
    getline(cin, bookName);
    cout << "Enter the name of the Author : ";
    fflush(stdin);
    getline(cin, authorName);
    cout << "Enter the name of the Publisher : ";
    fflush(stdin);
    getline(cin, publisherName);
    cout << "Enter the name of the Genre : ";
    fflush(stdin);
    getline(cin, genreName);
    cout << "Enter the number of Total Copies : ";
    cin >> totcpy;
    cout << "Enter the registration number : ";
    cin >> regno;

    bk = new Book(bookName, authorName, publisherName, genreName, totcpy, regno);
    b.push_back(bk);
}

void Librarian::viewBooks(vector<Book *> b)
{
    system("cls");
    for (int i = 0; i < b.size(); i++)
    {
        cout << "-----  " << i + 1 << "  -----" << endl;
        b[i]->display_book();
        cout << endl;
    }
    getch();
}

void Librarian::removeBook(vector<Book*>& b)
{
    system("cls");
    int serial;
    for (int i = 0; i < b.size(); i++)
    {
        cout << "-----  " << i + 1 << "  -----" << endl;
        b[i]->display_book();
        cout << endl;
    }
    cout <<"\n\nPress '0' To Go back ,OR ";
    cout <<"\nEnter The Serial Number of Book That Should Be Removed ---  ";
    cin >> serial;
    if (serial == 0)
        return;
    b.erase(b.begin() + serial - 1);
}