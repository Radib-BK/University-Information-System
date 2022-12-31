#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<process.h>
#include<conio.h>

using namespace std;

//userName will be the id of the student/teacher/librarian etc and will come from main.cpp
//password will be hardcoded into the txt file or be set while registering
//in the main.cpp we can use this username to identify which person is trying to login.

bool loginScreen(string userName, string password, int type)
{
    string match;
    userName = userName + password;

    if (type == 1)
    {
        fstream sFile;
        sFile.open("Login/studentLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }

    else if (type == 2)
    {
        fstream sFile;
        sFile.open("Login/teacherLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }

    else if (type == 3)
    {
        fstream sFile;
        sFile.open("Login/librarianLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }

    else if (type == 4)
    {
        fstream sFile;
        sFile.open("Login/headTeacherLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }

    else if (type == 5)
    {
        fstream sFile;
        sFile.open("Login/accountantLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }
    
    else if (type == 6)
    {
        fstream sFile;
        sFile.open("Login/administratorLogin.txt", ios::in);
        if (sFile.is_open())
        {
            while (getline(sFile,match))
            {
                if (match == userName)
                {
                    cout << "\n\n\n\t!!! Login Successful !!!" << endl;
                    getch();
                    sFile.close();
                    return true;
                }
            }
            cout << "\n\n\n\t!!! Login Failed !!!";
            getch();
            sFile.close();
            return false;
        }
        else
            return false;
    }
    return false;
}