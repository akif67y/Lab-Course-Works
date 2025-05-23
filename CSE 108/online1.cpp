#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private: 
    double x;
    double y;
    public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    void setCoordinates(double x, double y){
        this->x = x;
        this->y = y;
    }
    Point translate(double dx, double dy) {
        Point temp(this->x, this->y); // gadhar baccha eita keu kemne bhul kore// prothome temp initialize e korinai
        temp.x += dx;
        temp.y += dy;
        return temp;
    }
    double cross(const Point& other){
        double temp = x * other.y - y * other.x ;
        return temp;
    } 
    double getDistance(const Point& other){
        double temp;
        int a = (x-other.x);
        int b = (y-other.y);
        temp = sqrt(a*a + b*b);
        return temp;
    }
    void display(){
        cout <<"("<< x <<",";
        cout <<""<< y <<")\n";
    }


};


class Polygon{
    private :
    Point *vertices;
    int numVertices;
    public: // gadhar moto public dichilam
    Polygon(){
        vertices = new Point[10];
        numVertices = 0;
    }
    Polygon(Point *vertices, int n){
        numVertices = n;
        this->vertices = new Point[n];
        for(int i = 0; i < n; i++){
            this->vertices[i] = vertices[i];
        }
    }
    Polygon(const Polygon& temp){
        numVertices = temp.numVertices;
        vertices = new Point[numVertices];
        for(int i = 0; i < numVertices; i++){
            vertices[i] = temp.vertices[i];
        }
    }
    void addVertex(Point p){ // chodnar moto code
      Point temp[numVertices];
      for(int i = 0; i < numVertices; i++){
        temp[i] = vertices[i];
      }
      delete[] vertices;
      numVertices++;
      vertices = new Point[numVertices+1];
      for(int j = 0; j < numVertices-1; j++){
        vertices[j] = temp[j];
      }
      vertices[numVertices-1] = p;

    }
    

    double getPerimeter(){
        double ans = 0;
        for(int i = 0; i < numVertices -1; i++){
            ans += vertices[i+1].getDistance(vertices[i]);
        }
        // last one dite bhule gechi
        ans+= vertices[numVertices-1].getDistance(vertices[0]);
        return ans;
    } 
    

    double getArea() {
        double area = 0;
        for(int i = 0; i < numVertices -1; i++){
            area += vertices[i].cross(vertices[i+1]);
        }
        area += vertices[numVertices-1].cross(vertices[0]);
        return area/2;

    }

    Polygon translate(double dx, double dy) {
        Polygon temp(*this);
        for(int i= 0; i < numVertices; i++){
            temp.vertices[i] = temp.vertices[i].translate(dx, dy); // translate works differently
        }
        return temp;
    }

    void display(){
        for(int i = 0; i < numVertices; i++){
            vertices[i].display();
        }
       cout << "Area: "<< getArea() <<"\n";
      cout << "Perimeter: "<< getPerimeter()<<"\n";
    } 

    ~Polygon(){
        delete [] vertices;
    }


};




int main() {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);

    Point vertices[] = {p1, p2, p3};
    Polygon triangle(vertices,3);
    Polygon translatedTriangle = triangle.translate(2, 1);
    cout << "Original Triangle:\n";
    triangle.display();
    cout << "\nTranslated Triangle:\n";
    translatedTriangle.display();
    Polygon square = triangle;
    square.addVertex(p4);
    cout << "\nSquare:\n";
    square.display();
    return 0;
    }