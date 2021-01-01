#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* title, const char* isbn, int price)
        : price(price)
    {
        this->title = new char[strlen(title) + 1]; strcpy(this->title, title);
        this->isbn = new char[strlen(isbn) + 1]; strcpy(this->isbn, isbn);
    }
    Book(const Book& ref)
        : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1]; strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1]; strcpy(isbn, ref.isbn);
    }
    void ShowBookInfo() const
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    Book& operator=(const Book& ref)
    {
        delete []title;
        delete []isbn;
        title = new char[strlen(ref.title) + 1]; strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1]; strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }
    ~Book()
    {
        //cout << "called Book destructor" << endl;
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
/*
접근불가:
    char* title;
    char* isbn;
    int price;
*/
private:
    char* DRMKey;
public:
    EBook(const char* title, const char* isbn, int price, const char* DRMKey)
        : Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(this->DRMKey, DRMKey); 
    }
    EBook(const EBook& ref)
        : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1]; strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    ~EBook()
    {
        //cout << "called EBook destructor" << endl;
        delete []DRMKey;
    }
};



int main(void)
{
    Book book1("좋은 C", "555-67890-123-0", 15000);
    Book book2(book1);
    book2.ShowBookInfo();
    Book book3("좋은 C++", "555-12345-890-0", 20000);
    book3 = book1;
    book3.ShowBookInfo();
    cout << endl;
    EBook ebook1("좋은 C ebook", "555-67890-123-1", 8000, "fxdwq213t6dsfs");
    EBook ebook2(ebook1);
    ebook2.ShowEBookInfo();
    EBook ebook3("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook3 = ebook1;
    ebook3.ShowEBookInfo();
    return 0;
}