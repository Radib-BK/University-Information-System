#pragma once
#include "utilities.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
  protected:
    string name;
    string address;
    date dob;
    string email;

  public:
    // Constructors
    Person();
    Person(string name, string address, date dob, string email);

    // Getter functions
    string get_name();
    string get_address();
    string get_email();
    date get_dob();
    int get_dob_d();
    int get_dob_m();
    int get_dob_y();
    // setter functions
    void set_name(string name);
    void set_address(string address);
    void set_email(string email);
    void set_dob(int day, int month, int year);

    // Display Functions
    void show_dob(); // will print like "1 January, 2000"
};
