#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    int curpos;
    int maxsize;
    int cursize;
    // declare variables you need
} arrayList;

void init(arrayList* list)
{   list->cursize = 0;
    list->maxsize = 0;
    list->curpos = -1;
    // implement initialization
}

void free_list(arrayList* list)
{
    free(list->array);
    // implement destruction of list
}

void increase_capacity(arrayList* list)
{
    if(list->maxsize == 0){
        list->array = (int *)malloc(sizeof(int)*1);
        list->maxsize = 1;
        return;
    }
    int *temparray = (int *)malloc(sizeof(int) * list->cursize); // temp array created
    for(int i = 0; i < list->cursize; i++){
        temparray[i] = list->array[i]; // all value taken
    }
    free(list->array);  // originial freed
    list->maxsize *= 2; // max fixed
    list->array = (int *)malloc(sizeof(int) * list->maxsize ); // new double size array
    for(int i = 0; i < list->cursize; i++){
       list->array[i] =  temparray[i] ; // all element inserted back
    }
    if(list->maxsize > 2)
    printf("Capacity increased from %d to %d\n", list->maxsize/2, list->maxsize);
    free(temparray);
}

void decrease_capacity(arrayList* list)
{   
    if(list->maxsize == 1){
        free(list->array);
        list->maxsize = 0;
        list->cursize = 0;
    }
    int *temparray = (int *)malloc(sizeof(int) * list->cursize); // temp array created
    for(int i = 0; i < list->cursize; i++){
        temparray[i] = list->array[i]; // all value taken
    }
    free(list->array);  // originial freed
    list->maxsize /= 2; // max fixed
    list->array = (int *)malloc(sizeof(int) * list->maxsize ); // new double size array
    for(int i = 0; i < list->cursize; i++){
       list->array[i] =  temparray[i] ; // all element inserted back
    }
    if(list->maxsize > 1)
    printf("Capacity decreased from %d to %d\n", list->maxsize*2, list->maxsize);
    // implement capacity decrease
    free(temparray);
}

void print(arrayList* list)
{
    // implement list printing
    printf("[");
    int i;
    for( i = 0; i < list->cursize; i++){
        printf("%d ", list->array[i]);
        if(i == list->curpos){
            printf("| ");
        }
    }
    if(i == 0){
        printf(".");
    }
    printf("]");
    printf("\n");
}

void insert(int item, arrayList* list)
{   
    if((list->cursize+1) * 2 > list->maxsize){
        increase_capacity(list);
    }
    for(int i = list->cursize - 1; i > list->curpos; i--){
        list->array[i+1] = list->array[i];
    }
    list->array[list->curpos + 1] = item;
    list->curpos++;
    list->cursize++;
   
    
    
}

int delete_cur(arrayList* list)
{
    // implement deletion of current index function
    int temp = list->array[list->curpos];
    for(int i = list->curpos; i < list->cursize - 1; i++){
        list->array[i] = list->array[i+1];
    }
    list->cursize--;
    if((list->cursize) * 4 < list->maxsize){
        decrease_capacity(list);
    }
    if(list->curpos >= list->cursize){
        list->curpos = list->cursize - 1;
    }
    return temp;
}

void append(int item, arrayList* list)
{
    // implement append function
    if((list->cursize+1) * 2 > list->maxsize){
        increase_capacity(list);
    }
    list->array[list->cursize] = item;
    list->cursize++;
    if(list->curpos == -1){
        list->curpos = 0;
    }
    
}

int size(arrayList* list)
{
    return list->cursize;
    // implement size function
}

void prev(int n, arrayList* list)
{
    int temp = list->curpos - n;
    if(temp <0){
        temp = 0;
    }
    list->curpos = temp;
    // implement prev function
}

void next(int n, arrayList* list)
{
    // implement next function
    int temp = list->curpos + n;
    if(temp >= list->cursize){
        temp = list->cursize-1;
    }
    list->curpos = temp;
}

int is_present(int n, arrayList* list)
{
    // implement presence checking function
    for(int i = 0; i < list->cursize; i++){
        if(n == list->array[i]){
            return 1;
        }
    }
    return 0;
}

void clear(arrayList* list)
{
    // implement list clearing function
    free_list(list);
    init(list);
}

void delete_item(int item, arrayList* list)
{
    // implement item deletion function
    int dream = -1;
    for(int i = 0; i < list->cursize; i++){
        if(item == list->array[i]){
            dream = i;
            break;
        }
    }
    if(dream != -1){

    for(int i = dream; i < list->cursize - 1; i++){
        list->array[i] = list->array[i+1];
    }
    list->cursize--;
    if((list->cursize) * 4 < list->maxsize){
        decrease_capacity(list);
    }
    if(list->curpos >= list->cursize){
        list->curpos = list->cursize - 1;
    }
    }

}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
}

// you can define helper functions you need