#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
class Fraction{
    private:
     int numerator;
     int denominator;
     public:
     Fraction(){
        numerator = 0;
        denominator = 1;
     }
     Fraction(float a, float b){
        int num = ((int)(a * 100)) * 100;
        int den = ((int)(b * 100)) * 100;
        int temp = gcd(num,den);
        numerator =  num/ temp;
        denominator = den /temp;
     }
     Fraction(int a, int b){
        if(b == 0){
            std::cout << "Your input is wrong";
            numerator = 0;
            denominator = 1;
        }
        else{
        int temp = gcd(a,b);
        numerator = a / temp;
        denominator = b/temp;
        }
    }
     Fraction operator+(const Fraction &ob) const{
        int num = ob.numerator * denominator + numerator * ob.denominator;
        int den = ob.denominator *denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator-(const Fraction &ob) const{
        int num = - ob.numerator * denominator + numerator * ob.denominator;
        int den = ob.denominator *denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator*(const Fraction &ob)const {
        int num = numerator * ob.numerator;
        int den = denominator * ob.denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator/(const Fraction &ob) const{
        int num = numerator * ob.denominator;
        int den = denominator * ob.numerator;
        Fraction temp(num, den);
        return temp;
     }
       Fraction operator+(float x) const {
        Fraction ob(x,(float)1);
        return  *this + ob;
        
     }
       Fraction operator-(float x) const{
        Fraction ob(x,(float)1);
        return *this - ob;
     }
       Fraction operator*(float x) const{
        Fraction ob(x,(float)1);
        return (*this) * ob;
     }
      Fraction operator/(float x) const{
        Fraction ob(x,(float)1);
        return (*this) / ob;
     }

    Fraction& operator+=(const Fraction &ob){
        Fraction temp;
        temp = (*this)+ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator-=(const Fraction &ob){
        Fraction temp;
        temp = (*this)-ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator*=(const Fraction &ob){
        Fraction temp;
        temp = (*this)*ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator/=(const Fraction &ob){
        Fraction temp;
        temp = (*this)/ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
    Fraction& operator+=(float x){
        Fraction temp(x, float(1));
        return *this += temp;
        
    }
     Fraction& operator-=(float x){
        Fraction temp(x, float(1));
        return *this -= temp;
        
    }
     Fraction& operator*=(float x){
        Fraction temp(x, float(1));
        return *this *= temp;
        
    }
     Fraction& operator/=(float x){
        Fraction temp(x, float(1));
        return *this /= temp;
        
    }
    Fraction sqrtin() const{
        float x = sqrt((float) numerator); 
        float y = sqrt((float) denominator);
        Fraction a(x,y);
        return a;

    }
    
    friend Fraction operator+(float x,const Fraction &ob);
    friend Fraction operator*(float x, const Fraction &ob);
    friend Fraction operator-(float x, const Fraction &ob);
    friend Fraction operator/(float x, const Fraction &ob);
    friend ostream& operator<<(ostream &out, const Fraction &op);
     friend istream& operator>>(istream &in, Fraction &op);

    
};
Fraction operator+(float x, const Fraction &ob){
    return ob + x;
}
Fraction operator*(float x, const Fraction &ob){
    return ob*x;
}
Fraction operator-(float x, const Fraction &ob){
    Fraction temp(x,(float)1);
    return temp - ob;
}
Fraction operator/(float x,const Fraction &ob){
    Fraction temp(x,(float)1);
    return temp/ob;
}

ostream& operator<<(ostream &out, const Fraction &op){
    out <<"(" << op.numerator <<"/"<< op.denominator<<")";
    return out;
}
istream& operator>>(istream &in, Fraction &op){
    cout <<"Fraction: (x/y) : ";
    in >> op.numerator >> op.denominator;
    return in;
}

class FractionVector{
    private:
    Fraction *vectors;
    int size;
    public:
    explicit FractionVector(int n){
        size = n;
        vectors = new Fraction[n];
  
    }
    FractionVector(){
        size = 0;
        vectors = nullptr;
    }
    FractionVector(const FractionVector& ob){
        size = ob.size;
        vectors = new Fraction[size];
        
        for(int i = 0; i < size; i++){
            vectors[i] = ob.vectors[i];
        }
    }
  
    Fraction& operator[](int pos) const{
        if(pos >= size){
            std::cout <<"out of order\n";
            exit(1);
        }
        
            return vectors[pos]; 
        
    }
        Fraction& operator[](int pos){
        if(pos >= size){
            std::cout <<"out of order\n";
            exit(1);
        }
     
            return vectors[pos]; 
        
    }
    FractionVector operator+(const FractionVector &ob) const{ // eikhane adress dile
        if(size != ob.size){
            cout <<"addition not possible";
            exit(1);
        }
      
            FractionVector temp(size);
            for(int i = 0; i < size; i++){
                temp[i] = ob[i] + vectors[i]; // eikhane adress + fraction er jonno operator nao pete pare
            }
            return temp;
        
    }
      FractionVector operator-(const FractionVector &ob) const{
        if(size != ob.size){
            cout <<"subtraction not possible";
            exit(1);
        }
        
            FractionVector temp(size);
            for(int i = 0; i < size; i++){
                temp[i] = vectors[i] - ob[i];
            }
            return temp;
        
    }
    Fraction operator*(const FractionVector &ob) const{
        if(ob.size != size){
            cout <<"Not possible\n";
            exit(1);

        }
       
            Fraction ans(0,1);
            for(int i = 0; i < size; i++){
                Fraction temp;
                 temp = (vectors[i] * ob[i]);
                 ans += temp;
            }
            return ans;
        
    }
    FractionVector operator*(float frac) const{  
        FractionVector temp(size);
        for(int i = 0; i < size; i++){
            temp[i] = vectors[i] * frac;
        }
        return temp;
    }
    FractionVector operator/(float frac) const{
        FractionVector temp(size);
        for(int i = 0; i < size; i++){
            temp[i] = vectors[i]/frac;
        }
        return temp;
    }
    friend FractionVector operator*(float frac, const FractionVector &ob);

    Fraction value() const{
        Fraction ans;
        for(int i = 0; i < size; i++){
            Fraction temp;
            temp =  vectors[i] * vectors[i];
            ans += temp;
        }
        Fraction temp;
        temp = ans.sqrtin();
        return temp;
    }
    FractionVector& operator=(const FractionVector& ob){
      
        if(size >0) delete []vectors;
        size = ob.size;
        vectors = new Fraction[size];
        
        for(int i = 0; i < size; i++){
            vectors[i] = ob.vectors[i];
        }
        return *this;
    }
    void reallocatememory(int n){
        if(size > 0){delete []vectors;}
        size = n;
        vectors = new Fraction[n];
       
    }

    int getsize() const{
        return size;
    }
      ~FractionVector(){
        delete []vectors;
    }
    friend ostream& operator<<(ostream &out, const FractionVector &op);
     friend istream& operator>>(istream &in, FractionVector &op);
};

ostream& operator<<(ostream &out,const FractionVector &op){
    out <<"[ ";
    for(int i = 0; i < op.size; i++){
       out << op[i] ; 
        if(i < op.size -1){
            out <<", ";
        }
        else{
            out <<" ";
        }
    }
    out <<"]";
    return out;

}
istream& operator>>(istream &in,  FractionVector &op){
    cout <<"Input: " << op.size <<" Numbers: "<<'\n';
    for(int i = 0; i < op.size; i++){
        in >> op.vectors[i];
    }
    return in;

}

FractionVector operator*(float frac, const FractionVector &ob){
    return ob*frac;
}
class FractionMatrix{
    private:
    FractionVector *rows;
    FractionVector *cols;
     int rowcount ;
     int colcount;
    public:
    FractionMatrix(int r, int c){
        rowcount = r;
        colcount = c;
        rows = new FractionVector[r];
        
        for(int i = 0; i < r; i++){
            rows[i].reallocatememory(c);
        }
        cols = new FractionVector[c];
    
        for(int i = 0; i < c; i++){
            cols[i].reallocatememory(r);
        }
    }
    FractionMatrix(){
        rowcount = 0;
        colcount = 0;
        rows = nullptr;
        cols = nullptr;
    }
    FractionMatrix(const FractionMatrix& ob){
        rowcount = ob.rowcount;
        colcount = ob.colcount;
        rows = new FractionVector[rowcount];
        
        cols = new FractionVector[colcount];
        
        for(int i = 0; i < rowcount; i++){
            rows[i] = ob[i];
        }
        for(int i = 0; i < colcount; i++){
            cols[i] = ob.getColumn(i);
        }
        
    }
    FractionMatrix& operator=(const FractionMatrix &ob){
        if(rowcount > 0){delete []rows;}
        if(colcount > 0){delete []cols;}
        rowcount = ob.rowcount;
        colcount = ob.colcount;
        rows = new FractionVector[rowcount];
      
        cols = new FractionVector[colcount];
        
        for(int i = 0; i < rowcount; i++){
            rows[i] = ob[i];
        }
        for(int i = 0; i < colcount; i++){
            cols[i] = ob.getColumn(i);
        }
        return *this;
    }
    FractionVector& operator[](int pos)const {
        return rows[pos];
    }
    FractionVector& operator[](int pos){
        return rows[pos];
    }
    FractionVector  getColumn(int indx) const{
        if(indx >= colcount){
            cout<<"Out of bounds\n";
             exit(1);
        }
         return cols[indx];
    }
    void colfix(){
        for(int i = 0; i < colcount; i++){
            
            for(int j = 0; j < rowcount; j++){
                cols[i][j] = rows[j][i];
            }
        }
    }
    FractionMatrix operator+(const FractionMatrix &ob)const{
        //dimention check
        if(rowcount != ob.rowcount || colcount != ob.colcount){
            cout <<"Addition not possible\n";
            exit(1);
        }
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] + ob[i];
        }
        temp.colfix();
        return temp;
    }
      FractionMatrix operator-(const FractionMatrix &ob) const{
        //dimention check
        if(rowcount != ob.rowcount || colcount != ob.colcount){
            cout <<"subtraction not possible\n";
            exit(1);
        }
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] - ob[i];
        }
        temp.colfix();
        return temp;
    }
      FractionMatrix operator%(const FractionMatrix &ob) const{
       
        if(rowcount != ob.rowcount || colcount != ob.colcount){
            cout <<"Hardon not possible\n";
            exit(1);
        }
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            FractionVector drim(colcount);
            for(int j = 0; j < colcount; j++){
                temp[i][j] = rows[i][j] * ob[i][j];
            }
        }
        temp.colfix();
        return temp;
    }
     FractionMatrix operator*(const FractionMatrix &ob) const{
      
        if(colcount != ob.rowcount){
            cout <<"Multiplication not possible\n";
            exit(1);
        }
        FractionMatrix temp(rowcount, ob.colcount);
        for(int i = 0; i < rowcount; i++){
            for(int j = 0; j < ob.colcount; j++){
                temp[i][j] = rows[i] * ob.getColumn(j);   
            }
          
        }
        temp.colfix();
        return temp;
     }
     void transpose(){
        int temp = rowcount; // temp is the rowcount prev
        rowcount = colcount;
        colcount = temp;
         // rowcount is the prev colcount;
        delete[] rows;
        rows = new FractionVector[rowcount];
       
        for(int i = 0; i < rowcount; i++){
            rows[i].reallocatememory(colcount);
        }
        for(int i = 0; i < rowcount; i++){
            rows[i] = getColumn(i);
        }
        delete []cols;
        cols = new FractionVector[colcount];
       
        for(int i = 0; i < colcount; i++){
           cols[i].reallocatememory(rowcount);
        }
        colfix();
     }
     FractionMatrix operator*(float x) const{
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] * x;
        }
        temp.colfix();
        return temp;
     }
     FractionMatrix operator/(float x) const{
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] / x;
        }
        temp.colfix();
        return temp;
     }
    ~FractionMatrix(){
        delete []rows;
        delete []cols;
    }
    

friend ostream& operator<<(ostream& out, const FractionMatrix &m );
friend istream& operator>>(istream&in, FractionMatrix &m);
friend FractionMatrix operator*(float x, const FractionMatrix &m);
};

ostream& operator<<(ostream& out, const FractionMatrix &m ){
    for(int i = 0; i < m.rowcount; i++){
        out << m.rows[i];
        out <<"\n";
    }
    return out;
}
istream& operator>>(istream&in, FractionMatrix &m){
    cout <<"Enter vectors: \n";
     for(int i = 0; i < m.rowcount; i++){
        cout <<"row " << i + 1 <<": \n";
        in >> m.rows[i];
    }
    m.colfix();
    return in;
}
 FractionMatrix operator*(float x, const FractionMatrix &m) {
        FractionMatrix temp(m.rowcount, m.colcount);
        temp = m * x;
        return temp;
}

int main() {
  

    
    cout << "Fraction & Fraction Operations ==\n";
    Fraction f1, f2;
    cout << "Enter two fractions (numerator denominator)\n> ";
    cin >> f1 >> f2;

    cout << "\nYou entered:\n"
         << "  f1 = " << f1 << "\n"
         << "  f2 = " << f2 << "\n";

    cout << "Results:\n"
         << "  f1 + f2 = " << (f1 + f2) << "\n"
         << "  f1 - f2 = " << (f1 - f2) << "\n"
         << "  f1 * f2 = " << (f1 * f2) << "\n"
         << "  f1 / f2 = " << (f1 / f2) << "\n";
    float x = 6.21f;
    cout << "== Fraction & Float Operations (x = " << x << ") ==\n"
         << "  f1 = " << f1 << "\n"
         << "  x  = " << x << "\n\n";

    cout << "f1 op x:\n"
         << "  f1 + x = " << (f1 + x) << "\n"
         << "  f1 - x = " << (f1 - x) << "\n"
         << "  f1 * x = " << (f1 * x) << "\n"
         << "  f1 / x = " << (f1 / x) << "\n\n";

    cout << "x op f2:\n"
         << "  x + f2 = " << (x + f2) << "\n"
         << "  x - f2 = " << (x - f2) << "\n"
         << "  x * f2 = " << (x * f2) << "\n"
         << "  x / f2 = " << (x / f2) << "\n\n";

    // --- VECTOR OPERATIONS ---
    cout << "== FractionVector Operations ==\n";
    FractionVector v1(3), v2(3);
    cout << "Enter 3 elements for vector v1:\n> ";
    cin >> v1;
    cout << "Enter 3 elements for vector v2:\n> ";
    cin >> v2;

    cout << "\nv1 = " << v1 << "\n"
         << "v2 = " << v2 << "\n\n";

    cout << "v1 + v2        = " << (v1 + v2) << "\n"
         << "v1 * scalar(x) = " << (v1 * x) << "\n"
         << "scalar(x) * v1 = " << (x * v1) << "\n"
         << "Dot(v1, v2)    = " << (v1 * v2) << "\n"
         << "|v1|           = " << v1.value() << "\n\n";

    // --- MATRIX OPERATIONS ---
    cout << "== FractionMatrix Operations ==\n";
    // dimensions chosen to allow addition, multiplication, Hadamard
    FractionMatrix m1(2, 2), m2(2, 2);
    cout << "Enter a 2X2 matrix m1 (row by row):\n";
    cin >> m1;
    cout << "Enter a 2X2 matrix m2 (row by row):\n";
    cin >> m2;

    cout << "\nm1:\n" << m1
         << "m2:\n" << m2 << "\n";

    cout << "m1 + m2       =\n" << (m1 + m2) << "\n"
         << "m1 * m2 (mul) =\n" << (m1 * m2) << "\n"
         << "m1 % m2 (Hadamard) =\n" << (m1 % m2) << "\n"
         << "x * m1 (scalar)    =\n" << (x * m1) << "\n"
         << "m1 * x (scalar)    =\n" << (m1 * x) << "\n";

    return 0;
}



