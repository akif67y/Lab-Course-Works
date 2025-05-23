#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;



class Vectors{
    private:
    int **list;
    int size;
    public :
    Vectors(int n){
        size = n;
        list = (int **) malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++){
            list[i] =(int*) malloc(3 * sizeof(int));
        }
    } 
    void print(){
        for(int i = 0; i < size; i++){
            cout << list[i][0] <<" "<< list[i][1] <<" "<< list[i][2]<<"\n";
        }
    }
    void set(int i, int x, int y, int z){
        list[i][0] = x;
        list[i][1]= y;
        list[i][2] = z;
        
    }
    int* get(int indx){
        return list[indx];
    }
    void add(int x, int y, int z){
        for(int i = 0; i < size; i++){
            list[i][0]+=x;
            list[i][1]+=y;
            list[i][2]+=z;
        }
    }
    int* add(){
        int *temp = (int*) malloc(3 * sizeof(int));
        temp[0] = temp[1] = temp[2] = 0;
        
        for(int i = 0; i < size; i++){
            temp[0] += list[i][0];
            temp[1] += list[i][1];
            temp[2] += list[i][2];
        }
        return temp;
    }


    ~Vectors(){
        for(int i = 0; i < size; i++){
            free(list + i);
        }
        free(list);
    }

};




int main() 
{ 
    cout<<"Hello World"<<'\n'; 
 
    Vectors m(3); 
    for(int i=0; i<3; i++) 
        for(int j=0; j<3; j++) 
            m.set(i,i+j,i-j,i*j); 
             
    m.print(); 
    int* array = m.get(0); 
    cout<<array[0]<<' '<<array[1]<<' '<<array[2]<<'\n'; 
    m.set(0,100,100,100); 
    array = m.get(0); 
    cout<<array[0]<<' '<<array[1]<<' '<<array[2]<<'\n'; 
    m.add(100,100,100); 
    m.print(); 
     
    array = m.add(); 
    cout<<array[0]<<' '<<array[1]<<' '<<array[2]<<'\n';
    free(array); 
     
    return 0; 
 
}