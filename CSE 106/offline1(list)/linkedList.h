#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int element;
    struct node* next;
    struct node* prev;
} node;
typedef struct 
{    // declare head, tail, cur and other variables you need
    node*head ;
    node*tail ;
    node *cur ;

} linkedList;

void init(linkedList* list)
{
    // implement initialization
    list->head = list->tail = list->cur = NULL;

}

void free_list(linkedList* list)
{   
    if(list->head == NULL){
        return;
    }
    node*ahead ;
    node *temp = list->head;
    while(temp!= NULL){
        ahead = temp->next;
        free(temp);
        temp = ahead;
    }
    list->head = list->tail = list->cur = NULL;
    
    // implement destruction of list

}

void print(linkedList* list)
{   
    if(list->head == NULL){
        printf("[.]");
        return;
    }
    node *temp ;
    temp = list->head;
    printf("[");
    while(temp != NULL){
        printf("%d ", temp->element);
        if(temp == list->cur){
            printf("|");
        }
        temp = temp->next;
        
    }
    
    printf("]\n");
    // implement list printing
}

void insert(int item, linkedList* list)
{   
    node *temp = (node *)malloc(sizeof(node));
    temp->element = item;
    if(list->head == NULL){
      temp->next = NULL;
      temp->prev = NULL;
      list->head = list->tail = temp;
      list->cur = temp;
    }
    else if(list->cur == list->tail){
        temp->next = NULL;
        temp->prev = list->tail;
        list->tail->next = temp;
        list->tail = temp;
        list->cur = temp;

    }
    else{
        temp->next = list->cur->next ;
        temp->prev = list->cur;
        list->cur->next = temp;
        temp->next->prev = temp;
        list->cur = temp;
    }

    // implement insert function
}

void delete_indx(linkedList*list, node*indx){

    if(indx == list->head){
        if(list->cur == list->head){
            list->head = list->tail = list->cur = NULL;
            return;
        }
        list->head = list->head->next ;
        list->head->prev = NULL;
        if(list->cur == indx){
            list->cur = list->head;
        }
        return;
    
}
else if(indx == list->tail){
  
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    if(list->cur == indx) list->cur = list->tail;
    return;
    
}
indx->prev->next = indx->next;
indx->next->prev = indx->prev;
if(list->cur == indx) list->cur = list->cur->next;
}

int delete_cur(linkedList* list)
{    int temp = list->cur->element;
     delete_indx(list, list->cur);
    return temp;
    // implement deletion of current index function

}

void append(int item, linkedList* list)
{ // what if shurutei append;
   
    node *temp = (node *)malloc(sizeof(node));
    temp->element = item;
    if(list->head == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        list->head = temp;
        list->tail = temp;
        list->cur = temp;
        return;
    }
    list->tail->next = temp;
    temp->prev = list->tail;
    temp->next = NULL;
    list->tail = temp;
    // implement append function
}

int size(linkedList* list)
{   int ans= 0;
    node *temp ;
    temp = list->head;
    while(temp != NULL){
        ans++;
        temp = temp->next;
    }
    free(temp);
    return ans;
    // implement size function
}

void prev(int n, linkedList* list)
{
    node *temp ;
    temp = list->cur;
    while(n > 0 && temp != list->head){
        temp = temp->prev;
        n--;
    }
    list->cur = temp;

    // implement prev function
}

void next(int n, linkedList* list)
{
    // implement next function
    
    node *temp;
    temp = list->cur;
    while(n > 0 && temp != list->tail){
        temp = temp->next;
        n--;
    }
    list->cur = temp;
}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
    node *temp = list->head;
    while(temp != NULL){
        if(temp->element == n){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void clear(linkedList* list)
{
    free_list(list);
    list->head = list->tail = list->cur = NULL;
    // implement list clearing function
}

void delete_item(int item, linkedList* list)
{

    // implement item deletion function
    node *temp = list->head;
    while(temp != NULL){
        if(temp->element == item){
        delete_indx(list, temp);
        break;
        }
        temp = temp->next;
    }
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
    node *temp1;
    node *temp2;
   
    temp1 = list->head;
    while(ind1 > 0 ){
        temp1 = temp1->next;
        ind1--;
    }
    temp2 = list->head;
    while(ind2 > 0 ){
        temp2 = temp2->next;
        ind2--;
    }

    int temp = temp2->element;
    temp2->element = temp1->element;
    temp1->element = temp;
}

// you can define helper functions you need