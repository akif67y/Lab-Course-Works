#include<bits/stdc++.h>
#include "queue.h"
using namespace std;

int main(){
    Queue *q = new ListQueue();
    for(int i = 0; i < 15; i++){
        try{
            q->enqueue(i);
        }
        catch(const char *s){
            cout << s <<"\n";
        }
    }
    cout <<q->toString() <<'\n';
    for(int i = 0; i < 16; i++){
          try{
            int t = q->dequeue();
            cout<<"dequeud: "<< t <<"\n";
        }
        catch(const char *s){
            cout << s <<"\n";
        }
    }
 
 cout <<q->toString() <<'\n';
    
}