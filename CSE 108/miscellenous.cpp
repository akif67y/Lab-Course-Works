#include<bits/stdc++.h>
#include<cstring>
#include<cstdlib>
using namespace std;



class Book{
    private : 
    int isbn;
    char *title;
    double price;
    public:
    Book(){
        isbn = -1;
        title = new char[100];
        strcpy(title, "No title");
        price = 0;
    }
    Book(char* title, int isbn, double price){
        this->isbn = isbn;
        this->price = price;
        this->title = new char[strlen(title)];
        strcpy(this->title, title);
    }
    Book(const Book& newbook){
        this->isbn = newbook.isbn;
        this->price = newbook.price;
        title = new char[strlen(newbook.title)];
        strcpy(this->title, newbook.title);
    }

    void setIsbn(int a){
        isbn = a;
    }
    void setprice(double d){
        price = d;
    }
    void settitle(char *t){
        free(title);
        title = (char *) malloc(sizeof(char) * strlen(t));
        strcpy(title, t);
    }
    int getIsbn(){
        return isbn;
    }
    double getPrice(){
        return price;
    }
    char* gettitle(){
        return title;
    }
    void print(){
        cout << "Title: "<< title <<'\n';
        cout << "ISBN: "<< isbn <<'\n';
        cout << "Price: "<<fixed<< setprecision(3)<< price <<'\n';
    }
    int TheSameBook(Book b){ // book passed as an argument, destructor call hobe
        if(b.isbn == this->isbn){
            return 1;
        }
        else{
            return 0;
        }
    }
    Book& operator=(const Book& temp){
        if(this == &temp){
            return *this;
        }
        free(title);
        title = (char *) malloc(sizeof(char) * strlen(temp.title));
        this->isbn = temp.isbn;
        this->price = temp.price;
        strcpy(this->title, temp.title);
        return *this;
    }
    Book generateNewEdition(int isbn, int price){ // bit by bit copy hobe, para
        Book temp(this->title, isbn, price );
        return temp;
    }

    ~Book(){
        delete[] title;
    }

};

int main(){
    Book ob1("drim", 32, 230);
    Book ob2("swapno", 33, 240);
    ob1.print();
    Book ob3(ob2);
   cout << ob1.gettitle() <<'\n';
   cout << ob2.getIsbn()<<'\n';
   ob3.settitle("heyyou");
   ob3.print();
   cout << ob1.TheSameBook(ob2)<<'\n';

   ob2.setIsbn(32);
   ob1.print();
   ob2.print();
   cout << ob1.TheSameBook(ob2)<<'\n';
   Book ob4;
   ob4 = ob1.generateNewEdition(36, 400);
   ob4.print();
   ob2.generateNewEdition(20, 100).print();
   




}