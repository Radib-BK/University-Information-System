#include "include/Book.h"
#include <iostream>
#include <string>
using namespace std;

int Book::total_book_count = 0;

Book::Book() : title(""), author(""), publisher(""), genre(""), totalCopies(0), registrationNumber(0) {}

Book::Book(string title, string author, string publisher, string genre, int totalCopies, int registrationNumber) {
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->genre = genre;
    this->totalCopies = totalCopies;
    this->availableCopies = totalCopies;
    this->registrationNumber = registrationNumber;
    total_book_count++;
}
Book::Book(string title, string author, string publisher, string genre, int totalCopies, int availableCopies, int registrationNumber) {
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->genre = genre;
    this->totalCopies = totalCopies;
    this->availableCopies = availableCopies;
    this->registrationNumber = registrationNumber;
    total_book_count++;
}
void Book::set_book_count(int totalCopies) {
    this->totalCopies = totalCopies;
}
string Book::get_title() {
    return title;
}
string Book::get_author() {
    return author;
}
string Book::get_publisher() {
    return publisher;
}
string Book::get_genre() {
    return genre;
}
int Book::get_total_count() { // static fuction to get total book count
    return total_book_count;
}

int Book::get_total_copies() {
    return totalCopies;
}
int Book::get_available_copies() {
    return availableCopies;
}
int Book::get_registration_number() {
    return registrationNumber;
}
void Book::decrease_available_copies() {
    availableCopies--;
}
void Book::increase_available_copies() {
    availableCopies++;
}
void Book::display_book() {
    cout << "================================================" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Copies Present: " << availableCopies << endl;
    cout << "Total Copies : " << totalCopies << endl;
}
