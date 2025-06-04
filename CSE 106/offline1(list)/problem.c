#include <stdio.h>
// #include "arrayList.h"
#include "linkedList.h"

int main()
{
    FILE* file = fopen("in_prob.txt", "r");
    if(file == NULL){
        return 1;
    }

    // arrayList dal, fl;
    linkedList dal, fl;
    
    // initialize the lists
    init(&dal);
    init(&fl);
    int func, param;
    while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Recruit %d\n", param);
             int temp = is_present(param,&fl);
             if(temp == 0){
                append(param, &dal);
             }
             else{
                printf("In the foes list, cannot recruit\n");
             }
             print(&dal);
            // implement logic here

        }
        else if(func == 2 && fscanf(file, "%d", &param) == 1){
            printf("Fire %d\n", param);
            // implement logic here
            delete_item(param, &dal);
            append(param, &fl);
            print(&dal);
            print(&fl);

        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Check %d\n", param);
            //implement logic here
            int fren =is_present(param, &dal);
            int fo = is_present(param, &fl);
            if(fren == 1){
                printf("Friend\n");
            }
            else if(fo == 1){
                printf("Foe\n");
            }
            else{
                printf("Neither\n");
            }
        }
        else{
            break;
        }
        printf("\n");
    }
   
    // free memory
    free_list(&dal);
    free_list(&fl);
    
    return 0;
}