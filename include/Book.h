#pragma once
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Book {
  private:
    string title;
    string author;
    string publisher;
    string genre;
    int totalCopies;
    int availableCopies;
    int registrationNumber;
    static int total_book_count;

  public:
    Book();                                                                                                     // will not increase the total count of books via default constructor
    Book(string title, string author, string publisher, string genre, int totalCopies, int registrationNumber); // will increase the count
    Book(string title, string author, string publisher, string genre, int totalCopies, int availableCopies, int registrationNumber);

    /*Not keeping any individual setter functions as book parameters initialized all at once*/

    void set_book_count(int v_count);

    string get_title();
    string get_author();
    string get_publisher();
    string get_genre();
    int get_total_copies();
    int get_available_copies();
    int get_registration_number();
    void decrease_available_copies();
    void increase_available_copies();
    static int get_total_count();
    void display_book();
};
