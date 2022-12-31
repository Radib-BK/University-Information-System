#include "include/BorrowedBooks.h"

BorrowedBooks::BorrowedBooks() : Book(), borrow_grant_status(false), issued_by("N/A") {}
BorrowedBooks::BorrowedBooks(string title, string author, string publisher, string genre, int totalCopies, int registrationNumber, bool borrow_grant_status, date borrowDate) : Book(title, author, publisher, genre, totalCopies, registrationNumber) {
    this->borrow_grant_status = borrow_grant_status;
    this->borrowDate = borrowDate;
    set_returnDate(borrowDate);
    this->returnDate = get_returnDate();
    this->issued_by = "N/A";
} // removed return date from constructor as it is calculated from borrow date

BorrowedBooks::BorrowedBooks(string title,
                             string author,
                             string publisher,
                             string genre,
                             int totalCopies,
                             int availableCopies,
                             int registrationNumber, string issued_by,
                             date borrowDate,
                             date returnDate) : Book(title, author, publisher, genre, totalCopies, registrationNumber) {
    this->borrow_grant_status = true;
    this->borrowDate = borrowDate;
    set_returnDate(borrowDate);
    this->returnDate = returnDate;
    this->issued_by = issued_by;
}
void BorrowedBooks::set_borrow_grant_status(bool grant) {
    borrow_grant_status = grant;
}
bool BorrowedBooks::get_borrow_grant_status() {
    return borrow_grant_status;
}
void BorrowedBooks::set_borrowDate(date d) {
    borrowDate = d;
}
date BorrowedBooks::get_borrowDate() {
    return borrowDate;
}
void BorrowedBooks::set_returnDate(date d) {
    d.month++; // has to return book after 1 month from borrow date
    if (d.month > 12) {
        d.month = 1;
        d.year++;
    }
    returnDate = d;
}
date BorrowedBooks::get_returnDate() {
    return returnDate;
}
void BorrowedBooks::set_issued_by(string x) {
    issued_by = x;
}
string BorrowedBooks::get_issued_by() {
    return issued_by;
}
