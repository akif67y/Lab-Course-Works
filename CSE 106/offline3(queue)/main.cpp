#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

/********************************* RANDOM ************************************/
#define LCG_MULTIPLIER (1103515245)
#define LCG_INCREMENT (12345)
#define LCG_MODULUS ((unsigned)~0 >> 1)
static unsigned int lcg_seed = 1;
void custom_srand(unsigned int seed)
{
    lcg_seed = seed;
}
int custom_rand()
{
    lcg_seed = (LCG_MULTIPLIER * lcg_seed + LCG_INCREMENT) % (LCG_MODULUS + 1);
    return lcg_seed;
}
int randomQueue(int seed = -1)
{
    static bool initialized = false;
    if (seed != -1 && !initialized)
    {
        custom_srand(seed);
        initialized = true;
        return -1;
    }
    cout << "randomQueue() called";
    return (custom_rand() % 2) + 1;
}
/*****************************************************************************/

int main()
{
    // freopen("test_input_1.txt", "r", stdin); // Test Case 1
    freopen("test_input_2.txt", "r", stdin); // Test Case 2
    freopen("output.txt", "w", stdout);
    // Initialize the random generator with a fixed seed
    // You should set the seed only once at the beginning of your program
    // NOTE: Do not modify the following lines.
    randomQueue(42);

    Queue *Q1 = new ListQueue();
    Queue *Q2 = new ListQueue();
    Queue *Q = new ArrayQueue();

    int N;
    cin >> N;
    int arrayoftimestamp[10001];
     bool merged = false;
    for (int i = 1; i <= N; i++)
    {
        // TODO: Edit here to add your own logic
       
        cout << "Operation "<< i <<" ";
        int f;
        cin >> f;
        switch(f){
            case 1:
               
                 int id, timestamp;
                 cin >> id >> timestamp;
                 cout <<"(Arrival " << id <<" "<< timestamp <<"): ";
                 arrayoftimestamp[id] = timestamp;
                 if(!merged){
                 if(Q1->empty() && Q2->empty()){
                        int ran = randomQueue();
                    if(ran == 1){Q1->enqueue(id);}
                    else{Q2->enqueue(id);}
                 }
                 else if(Q1->empty()){
                    Q1->enqueue(id);
                 }
                 else if(Q2->empty()){
                    Q2->enqueue(id);
                 }
                 else{
                    int t1 = Q1->back();
                    int t2 = Q2->back();
                    if(arrayoftimestamp[t1] < arrayoftimestamp[t2]){
                        Q1->enqueue(id);
                    }
                    else{
                        Q2->enqueue(id);
                    }
                 }
                 }
                 else{
                    Q->enqueue(id);
                 }
                 break;
                 
            case 2:
                 cin >> id >> timestamp;
                  cout <<"(Leave " << id <<" "<< timestamp <<"): ";
                 arrayoftimestamp[id] = timestamp;
                 if(!merged){
                    int count = 0;
                    int size1 = Q1->size();
                    while(count < size1){
                        int t = Q1->dequeue();
                        if(t != id){
                            Q1->enqueue(t);
                        }
                        count++;
                    }
                    count = 0;
                     int size2 = Q2->size();
                    while(count < size2){
                        int t = Q2->dequeue();
                        if(t != id){
                            Q2->enqueue(t);
                        }
                        count++;
                    }
                 }
                 else{
                     int size = Q->size();
                     int count = 0;
                    while(count < size){
                        int t = Q->dequeue();
                        if(t != id){
                            Q->enqueue(t);
                        }
                        count++;
                    }
                 }
                 break;
            case 3:
             merged = true;
              cout <<"(Merge): ";
             while(!Q1->empty() && !Q2->empty()){
                if(arrayoftimestamp[Q1->front()] < arrayoftimestamp[Q2->front()]){
                    int t = Q1->dequeue();
                    Q->enqueue(t);
                }
                else{
                    int t = Q2->dequeue();
                    Q->enqueue(t);
                }
             }
             while(!Q1->empty()){
                int t = Q1->dequeue();
                Q->enqueue(t);
             }
             while(!Q2->empty()){
                int t = Q2->dequeue();
                Q->enqueue(t);
             }
             break;
            case 4:
             cout <<"(Split): ";
            merged = false;
            while(!Q->empty()){
                int t1 = Q->dequeue();
                int t2 = 0;
                if(!Q->empty()){
                    t2 = Q->dequeue();
                }
                Q1->enqueue(t1);
                if(t2 != 0){
                    Q2->enqueue(t2);
                }
            }
            break;
            case 5:
            cout <<"(Departure): ";
            // on merged true
            if(!Q1->empty() && !Q2->empty()){
                int ran = randomQueue();
                if(ran == 1){
                    Q1->dequeue();
                }
                else{
                    Q2->dequeue();
                }
            }
            else if(!Q1->empty()){
                Q1->dequeue();
            }
            else if(!Q2->empty()){
                Q2->dequeue();
            }
            else{
                if(!Q->empty()){
                    Q->dequeue();
                }
            }
            break;

        }

        cout << "\nQ1: " <<Q1->toString() <<"\n";
        cout <<"Q2: " <<Q2->toString() <<"\n";
        cout << "Q: "<<Q->toString() <<"\n";
                // After each operation, we will check the queue's size and capacity
        // NOTE: Do not modify the following lines.
        int capacity = ((ArrayQueue *)Q)->getCapacity();
        if ((Q->size() < capacity / 4 && capacity > 2))
        {
            cout << "Error: Queue size is less than 25% of its capacity." << endl;
        }
        else if (capacity < 2)
        {
            cout << "Error: Queue capacity is less than 2." << endl;
        }
    }

    return 0;
}