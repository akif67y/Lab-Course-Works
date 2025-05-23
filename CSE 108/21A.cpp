#include<iostream>
#include<string>
using namespace std;



class Book{
    private:
    string title;
    string author;
    int availability;
    public:
    Book(){
        title = "";
        author = "";
        availability = 0;
    }
    void setBook(string title, string author, int availability){
        this->title = title;
        this->author = author;
        this->availability = availability;
    }
    string getTitle(){return title;}
    string getAuthor(){return author;}
    int getAvailability(){return availability;}
    void setAvailability(int a){this->availability = a;}
    void displayBook(){
        cout <<"Title: "<< title <<'\n';
        cout <<"Author: "<< author <<'\n';
        cout <<"Availabitliy : ";
        if(availability){
            cout << "Available\n";
        }
        else{
            cout <<"Not available\n";
        }
    }
    ~Book(){}

};


class LibraryMember{
    private :
    string name;
    int cardnum;
    public :
    LibraryMember(){
        name = " ";
        cardnum = -1;
    }
    void setLibraryMember(string name, int cardnum){
        this->name = name;
        this->cardnum = cardnum;
    }
    string getName(){return name;
    }
    int getcardnum(){return cardnum;}
    void displayLibraryMember(){
        cout <<"Name :" << name ;
        cout <<"\nCardno: "<< cardnum <<"\n";
    }
    ~LibraryMember(){
    }
};

class Library{
    private :
    int maxsize = 100;
    int curposbook;
    int curposlist;
    Book *booklist ;
    LibraryMember *memberlist;
    public: 
    Library(){
        maxsize = 100;
        curposbook = 0;
        curposlist = 0;
        booklist = new Book[maxsize];
        memberlist = new LibraryMember[maxsize];
    }
    void addBook(string title, string author){
        // jodi already filled thake casee pore
        booklist[curposbook].setBook(title,author,1);
        curposbook++;
    }
    void registerMember(string name, int cardnum){
        memberlist[curposlist].setLibraryMember(name, cardnum);
        curposlist++;
    }
    void borrowBook(string title, int cardnum){
        int i;
        for( i = 0; i < curposbook; i++){
            if(booklist[i].getTitle() == title){
                booklist[i].setAvailability(0);
                break;
            }
        }
        
        int j;
        for( j = 0; j < curposlist; j++){
            if(memberlist[j].getcardnum() == cardnum){
                break;
            }
        }
        cout << "Book" << booklist[i].getTitle() <<" has been borrowed by\n Name :"<<  memberlist[j].getName() << "\nLibrary Card Number: "<< cardnum <<'\n';

    }
    void returnBook(string title, int cardnum){
        int i;
        for( i = 0; i < curposbook; i++){
            if(booklist[i].getTitle()== title){
                booklist[i].setAvailability(1);
                break;
            }
        }
        int j;
        for( j = 0; j < curposlist; j++){
            if(memberlist[j].getcardnum() == cardnum){
               break;
            }
        }
        cout << "Book" << booklist[i].getTitle() <<" has been returned by\n Name :"<<  memberlist[j].getName() << "\nLibrary Card Number: "<< cardnum <<'\n';

    }
    void removeBook(string title){
        int i;
        for( i = 0; i < curposbook; i++){
            if(booklist[i].getTitle() == title){
                break;
            }
        }
        for(int j = i; j < curposbook-1; j++){
            booklist[j] = booklist[j+1];
        }
        curposbook--;
        cout <<"Book '" << title << "' was removed";
    }
    void removeMember(int cardnum){
        int j;
        for( j = 0; j < curposlist; j++){
            if(memberlist[j].getcardnum() == cardnum){
               break;
            }
        }
        cout << "Member " << memberlist[j].getName() <<"(" << memberlist[j].getcardnum() <<") has been removed\n";
        for(int i = j; i < curposlist-1; j++){
            memberlist[i] = memberlist[i+1];
        }
        curposlist--;
    }
    void displayAllBooks(){
        cout <<"Books in the Library: \n";
        for(int i = 0; i < curposbook; i++){
            booklist[i].displayBook();
        }
    }
    void displayAllMembers(){
        cout <<"Members in the library: \n";
        for(int j = 0; j < curposlist; j++){
            memberlist[j].displayLibraryMember();
        }
    }
    
    ~Library(){
        free(booklist);
        free(memberlist);
    }
};


    int main() {
        Library library;
        // Adding books
        library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
        library.addBook("To Kill a Mockingbird", "Harper Lee");
        library.addBook("Pride and Prejudice", "Jane Austen");
        cout << "\n";
        // Displaying all books
        library.displayAllBooks();
        cout <<"\n";
        // Registering members
        library.registerMember("John Doe", 1234);
        library.registerMember("Jane Smith", 5678);
        cout <<"\n";
        // Displaying all members
        library.displayAllMembers();
        cout <<"\n";
        // Borrowing books
        library.borrowBook("The Great Gatsby", 1234);
        library.borrowBook("To Kill a Mockingbird", 5678);
        cout <<"\n";
        // Displaying all books (after borrowing)
        library.displayAllBooks();
        cout <<"\n";
        // Returning a book
        library.returnBook("The Great Gatsby", 1234);
        cout <<"\n";
        // Displaying all books (after returning)
        library.displayAllBooks();
        cout <<"\n";
        // Removing a book
        library.removeBook("Pride and Prejudice");
        cout <<"\n";
        // Displaying all books (after removal)
        library.displayAllBooks();
        cout <<"\n";
        // Removing a member
        library.displayAllMembers();
        library.removeMember(5678);
        cout <<"\n";
        // Displaying all members (after removal)
        library.displayAllMembers();
        cout <<"\n";
        return 0;
        }

