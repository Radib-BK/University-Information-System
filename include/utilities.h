#pragma once
#include <iostream>

using namespace std;
struct date {
    int day;
    int month;
    int year;
};

void show_date(date d);
int getDobDay(date d);
int getDobMonth(date d);
int getDobyear(date d);