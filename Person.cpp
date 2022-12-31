#pragma once
#include "include/Person.h"

// Constructors
Person::Person() : name(""), address(""), dob({1, 1, 2000}), email("") {
}
Person::Person(string name, string address, date dob, string email) {
    this->name = name;
    this->address = address;
    this->email = email;
    this->dob = {dob.day, dob.month, dob.year};
}

// Getter Functions
string Person::get_name() {
    return name;
}
string Person::get_address() {
    return address;
}
string Person::get_email() {
    return email;
}
date Person::get_dob() {
    return dob;
}

// Setter Functions
void Person::set_name(string name) {
    this->name = name;
}
void Person::set_address(string address) {
    this->address = address;
}
void Person::set_email(string email) {
    this->email = email;
}
void Person::set_dob(int day, int month, int year) {
    dob = {day, month, year};
}

int Person:: get_dob_d()
{
    return dob.day;
}
int Person:: get_dob_m()
{
    return dob.month;
}
int Person:: get_dob_y()
{
    return dob.year;
}

// Display Functions
void Person::show_dob() {
    show_date(dob);
}
