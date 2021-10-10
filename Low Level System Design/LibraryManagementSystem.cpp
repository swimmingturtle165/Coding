#include <bits/stdc++.h>
using namespace std;

class Library{
    string name;
    Address location;
    vector<BookItem> books;
};

class Address{
    int pincode;
    string street;
    string city;
    string state;
    string country;

};

class Book{
    string uniqueId;
    string title;
    vector<Author> authors;
    string bookType;
    vector<BookItem> copies;
};

enum class bookType{

    HORROR , MYSTERY , THRILLER ,LOVE_STORY , COMEDY , SATIRE,
    HISTORY, WAR , SCI_FI

};

class BookItem:public Book{
    string barcode;
    Date publicationDate;
    Rack rackLocation;
    BookStatus bookStatus;
    BookFormat bookFormat;
    Date issueDate;
};

enum class BookFormat{

    HARDCOVER , PAPERBOUND , JOURNAL , NEWSPAPER

};

enum class BookStatus{
    
    AVAILABLE , ISSUED , RESERVED , LOST
};

class Date{
    int date;
    int month;
    int year;
};

class Rack{
    int row;
    int col;
    int position;
};

class Person{

    string firstName;
    string lastName;

};

class Author:public Person{
    vector<Book> booksWritten;
};

class SystemUser:public Person{

    string email;
    string phoneNumber;
    Account account;

};
class Member:public SystemUser{
    int totalBooksCheckedOut;
    Search searchObj;
    BookIssueService issueService;
};

class Librarian:public SystemUser{
    int totalBooksCheckedOut;
    Search searchObj;
    BookIssueService issueService;

    void addBookItem(BookItem b){

    }
    void deleteBookItem(string barcode){
        
    }
    void editBookItem(BookItem b){
        
    }
};

class Account{
    string userName;
    string password;
    int accountId;
};

class Search{
    vector<BookItem>
}

int main()
{

}