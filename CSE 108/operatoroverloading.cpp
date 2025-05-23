#include<iostream>
#include<cmath>
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
     Fraction operator+(Fraction &ob){
        int num = ob.numerator * denominator + numerator * ob.denominator;
        int den = ob.denominator *denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator-(Fraction &ob){
        int num = - ob.numerator * denominator + numerator * ob.denominator;
        int den = ob.denominator *denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator*(Fraction ob){
        int num = numerator * ob.numerator;
        int den = denominator * ob.denominator;
        Fraction temp(num, den);
        return temp;
     }
     Fraction operator/(Fraction ob){
        int num = numerator * ob.denominator;
        int den = denominator * ob.numerator;
        Fraction temp(num, den);
        return temp;
     }
       Fraction operator+(float x){
        Fraction ob(x,(float)1);
        return  *this + ob;
        
     }
       Fraction operator-(float x){
        Fraction ob(x,(float)1);
        return *this - ob;
     }
       Fraction operator*(float x){
        Fraction ob(x,(float)1);
        return (*this) * ob;
     }
      Fraction operator/(float x){
        Fraction ob(x,(float)1);
        return (*this) / ob;
     }

    Fraction& operator+=(Fraction &ob){
        Fraction temp;
        temp = (*this)+ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator-=(Fraction &ob){
        Fraction temp;
        temp = (*this)-ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator*=(Fraction &ob){
        Fraction temp;
        temp = (*this)*ob;
        numerator = temp.numerator;
        denominator = temp.denominator;
        return *this;
    }
      Fraction& operator/=(Fraction &ob){
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
    Fraction sqrtin(){
        
        float x = sqrt((float) numerator); 
        float y = sqrt((float) denominator);
        Fraction a(x,y);
        return a;

    }
    
    friend Fraction operator+(float x, Fraction &ob);
    friend Fraction operator*(float x, Fraction &ob);
    friend Fraction operator-(float x, Fraction &ob);
    friend Fraction operator/(float x, Fraction &ob);
    friend ostream& operator<<(ostream &out, const Fraction &op);
     friend istream& operator>>(istream &in, Fraction &op);

    
};
Fraction operator+(float x, Fraction &ob){
    return ob + x;
}
Fraction operator*(float x, Fraction &ob){
    return ob*x;
}
Fraction operator-(float x, Fraction &ob){
    Fraction temp(x,(float)1);
    return temp - ob;
}
Fraction operator/(float x, Fraction &ob){
    Fraction temp(x,(float)1);
    return temp/ob;
}

ostream& operator<<(ostream &out, const Fraction &op){
    out <<"(" << op.numerator <<","<< op.denominator<<")";
    return out;
}
istream& operator>>(istream &in, Fraction &op){
    cout <<"Enter coordinate (x,y)";
    in >> op.numerator >> op.denominator;
    return in;
}

class FractionVector{
    private:
    Fraction *vectors;
    int size;
    public:
    FractionVector(int n){
        size = n;
        vectors = new Fraction[n];
    }
    FractionVector(){
        size = 0;
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
        }
        else{
            return vectors[pos]; // this returning adress may create some problem
        }
    }
        Fraction& operator[](int pos){
        if(pos >= size){
            std::cout <<"out of order\n";
        }
        else{
            return vectors[pos]; // this returning adress may create some problem
        }
    }
    FractionVector operator+(FractionVector ob){ // eikhane adress dile
        if(size != ob.size){
            cout <<"addition not possible";
            return *this;
        }
        else{
            FractionVector temp(size);
            for(int i = 0; i < size; i++){
                temp[i] = ob[i] + vectors[i]; // eikhane adress + fraction er jonno operator nao pete pare
            }
            return temp;
        }
    }
      FractionVector operator-(FractionVector ob){
        if(size != ob.size){
            cout <<"subtraction not possible";
            return *this;
        }
        else{
            FractionVector temp(size);
            for(int i = 0; i < size; i++){
                temp[i] = vectors[i] - ob[i];
            }
            return temp;
        }
    }
    Fraction operator*(FractionVector ob){
        if(ob.size != size){
            cout <<"Not possible\n";
           Fraction temp;
           return temp;

        }
        else{
            Fraction ans(0,1);
            for(int i = 0; i < size; i++){
                Fraction temp;
                 temp = (vectors[i] * ob[i]);
                 ans += temp;
            }
            return ans;
        }
    }
    FractionVector operator*(float frac){
        FractionVector temp(size);
        for(int i = 0; i < size; i++){
            temp[i] = vectors[i] * frac;
        }
        return temp;
    }
    FractionVector operator/(float frac){
        FractionVector temp(size);
        for(int i = 0; i < size; i++){
            temp[i] = vectors[i]/frac;
        }
        return temp;
    }
    friend FractionVector operator*(float frac, FractionVector ob);

    Fraction value(){
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
      
        if(ob.size >0) delete []vectors;
        size = ob.size;
        vectors = new Fraction[size];
        for(int i = 0; i < size; i++){
            vectors[i] = ob.vectors[i];
        }
        return *this;

    }

    int getsize() {
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
            cout <<", ";
        }
        else{
            out <<" ";
        }
    }
    out <<"]";
    return out;

}
istream& operator>>(istream &in,  FractionVector &op){
    cout <<"size" << op.size <<'\n';
   
    cout <<"Enter elements\n";
    for(int i = 0; i < op.size; i++){
        in >> op.vectors[i];
    }
    return in;

}


FractionVector operator*(float frac, FractionVector ob){
    return ob * frac;
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
        cols = new FractionVector[c];
        // shobgulo fractionvector er size kintu 0
    }
    FractionMatrix(){
        rowcount = 0;
        colcount = 0;
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
            return cols[0];
        }
        else return cols[indx];
    }
    void colfix(){
        for(int i = 0; i < colcount; i++){
            FractionVector temp(rowcount);
            for(int j = 0; j < rowcount; j++){
                temp[j] = rows[j][i];
            }
            cols[i] = temp;
        }
    }
    FractionMatrix operator+(FractionMatrix &ob){
        //dimention check
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] + ob[i];
        }
        // er column type fixx kora lagbe
        for(int j = 0; j < colcount; j++){
            temp.cols[j] = cols[j] + ob.getColumn(j);
        }
        return temp;
    }
      FractionMatrix operator-(FractionMatrix &ob){
        //dimention check
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i] - ob[i];
        }
        // er column type fixx kora lagbe
        for(int j = 0; j < colcount; j++){
            temp.cols[j] = cols[j] - ob.getColumn(j);
        }
        return temp;
    }
      FractionMatrix operator%(FractionMatrix &ob){
        //dimention check
        FractionMatrix temp(rowcount, colcount);
        for(int i = 0; i < rowcount; i++){
            FractionVector drim(colcount);
            for(int j = 0; j < colcount; j++){
                drim[j] = rows[i][j] * ob[i][j];
            }
            temp[i] = drim;
        }
        // er column type fixx kora lagbe
        // for(int j = 0; j < colcount; j++){
        //  FractionVector drim(rowcount);
        //     for(int i = 0; i < rowcount; i++){
        //         drim[i] = cols[j][i] * (ob.getColumn(j))[i];
        //     }
        //       temp.cols[j] = drim;
        // }
        // colfix();
        temp.colfix();
        return temp;
    }
  




    void takeinput(){
        cout <<"Enter vectors\n";
    for(int i = 0; i < rowcount; i++){
        FractionVector temp(colcount);
        cin >> temp;
        rows[i] = temp;
    }
    for(int j = 0; j < colcount; j++){
        FractionVector temp(rowcount);
        for(int i = 0; i < rowcount; i++){
            temp[i] = rows[i][j];
        }
        cols[j] = temp;
    }
    }
    

friend ostream& operator<<(ostream& out, const FractionMatrix &m );

};

ostream& operator<<(ostream& out, const FractionMatrix &m ){
    for(int i = 0; i < m.rowcount; i++){
        out << m.rows[i];
        cout <<"\n";
    }
    return out;
}



int main(){
 
    FractionMatrix m(1,2);
    m.takeinput();
    cout << m;
    FractionMatrix m2(1,2);
    m2.takeinput();
    cout << m2;
    FractionMatrix m3;
    m3 = m % m2;
    cout << m3 ;
    cout << m3.getColumn(1);

    
    

   
    
    


    




}