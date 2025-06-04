#include <iostream>
#include<climits>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // default constructor
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int n)
    {
        numerator = n;
        denominator = 1;
    }
    Fraction(int a, int b)
    {
        int temp = gcd(a, b);
        a = a / temp;
        b = b / temp;

        numerator = a;
        denominator = b;
        if(numerator > 0 && denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }
    }
   
    Fraction add(Fraction &f)
    {
        int a = numerator * f.denominator + denominator * f.numerator;
        int b = denominator * f.denominator;
        Fraction temp(a, b);
        return temp;
    }
    Fraction add(int a){
        int x = numerator + denominator * a;
        int y = denominator;
        Fraction temp(x,y);
        return temp;
    }
    Fraction sub(Fraction &f){
        int a = numerator * f.denominator - denominator * f.numerator;
        int b = denominator * f.denominator;
        Fraction temp(a, b);
        return temp;
    }
    Fraction sub(int a){
        int x = numerator - denominator * a;
        int y = denominator;
        Fraction temp(x,y);
        return temp;
    }
 
   
    Fraction mul(Fraction &f){
        int x = numerator * f.numerator;
        int y = denominator * f.denominator;
        Fraction temp(x,y);
        return temp;
    }
    Fraction mul(int a){
        int x = numerator * a ;
        int y = denominator;
        Fraction temp(x,y);
        return temp;
    }
   
    Fraction div(Fraction &f){
        int x = numerator * f.denominator;
        int y = denominator * f.numerator;
        if( y == 0){
            cout <<"Cannot divide by 0\n";
            return *this;
        }
        Fraction temp(x,y);
        return temp;
    }
    Fraction div(int a){
        int x = numerator ;
        int y = denominator*a;
        if( y == 0){
            cout <<"Cannot divide by 0\n";
            return *this;
        }
        Fraction temp(x,y);
        return temp;
    }
  


    void setNum(int a)
    {
        numerator = a;
    }
    void setDen(int a)
    {
        denominator = a;
    }
    int getNum()
    {
        return numerator;
    }
    int getDen()
    {
        return denominator;
    }
    void print()
    {
        cout << numerator << "/" << denominator << "\n";
    }

    ~Fraction()
    {
        // lagbena
    }
};




class FractionCollection{
    private :
    Fraction *fractions;
    int maxlength;
    int length;

    public:
    FractionCollection(){
        fractions = new Fraction[10];
        maxlength = 10;
        length = 0;
    }
    FractionCollection(int n){
        fractions = new Fraction[n];
        maxlength = n;
        length = 0;
    }
    void insert(Fraction f){ 
        fractions[length] = f;
        length++;// 
    }
    void insert(int pos, Fraction f){
        if(length == maxlength){ // all filled hoile last value will be discared
            length--;
        }
        for(int i = length; i > pos; i--){
            fractions[i] = fractions[i-1];
        }
        fractions[pos]= f;
        length++;
    }
    // remove;
    void remove(){
        length--;
    }
    void remove(Fraction f){
        for(int i = 0; i < length; i++){
            if(f.getNum() == fractions[i].getNum() && f.getDen() == fractions[i].getDen()){
                
                for(int j = i ; j < length - 1; j++){
                    fractions[j] = fractions[j+1];
                }
                length--;
            }
        }
    }
    void remove(int pos){
        for(int j = pos; j < length - 1; j++){
            fractions[j] = fractions[j+1];
        }
        length--;

    }
    Fraction getmax(){
        double value =(double)INT_MIN;
        int ans = -1;

        for(int i = 0; i < length; i++){
            double temp = (double)fractions[i].getNum()/ fractions[i].getDen();
            if(temp > value){
                value = temp;
                ans = i;
            }
        }
        return fractions[ans];
    }
    Fraction getmin(){
        double value =(double)INT_MAX;
        int ans = -1;

        for(int i = 0; i < length; i++){
            double temp = (double)fractions[i].getNum()/ fractions[i].getDen();
            if(temp < value){
                value = temp;
                ans = i;
            }
        }
        return fractions[ans];
    }
    Fraction add(int start, int end){
        Fraction temp;
        for(int i = start ; i < end; i++){
            temp = temp.add(fractions[i]);
        }
        return temp;
    }
    Fraction mul(int start, int end){
        Fraction temp(1,1);
        for(int i = start ; i < end; i++){
            temp = temp.mul(fractions[i]);
        }
        return temp;
    }
    Fraction sub(int pos1,int pos2){
        return fractions[pos1].sub(fractions[pos2]);
    }
    Fraction div(int pos1,int pos2){
        return fractions[pos1].div(fractions[pos2]);
    }
    void print(){
        cout << "Fraction" << endl;
        cout << "-------------------------------" << endl;
        for(int i = 0; i < length; i++){
           cout <<"Fractions " << i<<" :"; 
           fractions[i].print();
        }

        
        cout <<"MAX: ";
        getmax().print();
        cout << "MIN: ";
        getmin().print();
        cout <<"Summation: ";
        add(0,length).print();
        cout <<"Multiplication: ";
        mul(0,length).print();
        cout << endl;
    }

    ~FractionCollection(){
        delete []fractions;
    }

};

int main()
{
    
   // Create Fractions with numerator and denominator
Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);

cout << "Fraction" << endl;
cout << "-------------------------------" << endl;

cout << "A: ";
a.print();

cout << "B: ";
b.print();

cout << endl;

cout << "Add(a, b): ";
a.add(b).print();

cout << "Add(a, 2): ";
a.add(2).print();

cout << "Sub(a, b): ";
a.sub(b).print();

cout << "Sub(a, 2): ";
a.sub(2).print();

cout << "Mul(a, b): ";
a.mul(b).print();

cout << "Mul(a, 2): ";
a.mul(2).print();

cout << "Div(a, b): ";
a.div(b).print();

cout << "Div(a, 2): ";
a.div(2).print();

cout << "Div(a, 0): ";
a.div(0).print();

//Collection of Fractions
Fraction e, f(5), g(10);
FractionCollection fc(10);

fc.insert(a);
fc.insert(b);
fc.insert(c);
fc.print();

cout << "Sub(Pos0, Pos1): ";
fc.sub(0, 1).print(); // subtracts the fraction at pos1 from fraction at pos0

cout << "Div(Pos0, Pos1): ";
fc.div(0, 1).print(); // divides the fraction at pos0 by the fraction at pos1

fc.remove(1);
fc.print();

fc.remove(a); 
fc.print();

fc.insert(d);
fc.insert(0, e); // insert at pos0
fc.insert(f);
fc.insert(g);
fc.print();

fc.remove(); // removes the last fraction
fc.print(); // notice the output

return 0;

}