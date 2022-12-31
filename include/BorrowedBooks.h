#pragma once
#include "Book.h"
#include "utilities.h"
class BorrowedBooks : public Book {
  private:
    /*
      From book class
      string title;
      string author;
      string publisher;
      string genre;
      int totalCopies;
      int availableCopies;
      int registrationNumber;
      static int total_book_count;
    */

    string issued_by;
    bool borrow_grant_status;
    date borrowDate;
    date returnDate;
    int serialNo;

  public:
    BorrowedBooks();
    BorrowedBooks(string title,
                  string author,
                  string publisher,
                  string genre,
                  int totalCopies,
                  int availableCopies,
                  int registrationNumber, string issued_by,
                  date borrowDate,
                  date returnDate);
    BorrowedBooks(string title, string author, string publisher, string genre, int totalCopies, int registrationNumber, bool borrow_grant_status, date borrowDate);

    /*
        From book class
        string get_title();
        string get_author();
        string get_publisher();
        string get_genre();
        int get_registration_Number();
        int get_total_copies();
        int get_available_copies();
        static int get_total_count();
        void display_book();
    */
    string get_issued_by();
    void set_issued_by(string x);
    void set_borrow_grant_status(bool grant);
    bool get_borrow_grant_status();
    void set_borrowDate(date d);
    void set_returnDate(date d);
    date get_borrowDate();
    date get_returnDate();
};