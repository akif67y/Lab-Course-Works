#include<bits/stdc++.h>
#include "queue.h"
using namespace std;

int main(){
    Queue *q = new ArrayQueue();
    for(int i = 0; i < 100; i++){
        try{
            q->enqueue(i);
        }
        catch(const char *s){
            cout << s <<"\n";
        }
    }
    q->toString();
    for(int i = 0; i < 101; i++){
          try{
            int t = q->dequeue();
            cout<<"dequeud: "<< t <<"\n";
        }
        catch(const char *s){
            cout << s <<"\n";
        }
    }
 
    q->toString();
    
}