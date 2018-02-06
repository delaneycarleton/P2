#include <stdio.h>
#include <stdlib.h>

struct IntArray
{
    int length;
    int *dataPtr;
};

int getInt()
{
    char buffer[1024];
    int isInt = 0;
    while(! isInt){
        fgets(buffer, 1024, stdin);
        if(buffer[0] != '\n' && buffer[0] != '\0'){
            isInt = 1;
        }
        int i = 0;
        while(buffer[i] != '\n' && buffer[i] != '\0'){
            if(buffer[i] < '0'|| buffer[i] > '9'){
                isInt = 0; 
            }
            i++;
        }  
    }
    return atoi(buffer);
}
/*makes character buffer of 1024 and sets isInt to 0. use while loop for not isInt and if buffer indexed at 0 does not equal new line and does not equal null, isInt equal 1. set int i equal to 0 and while buffer at indexed i is less than 0 or greater than 0, isInt equal 0. This will determine if it is an integer*/    

struct IntArray* mallocIntArray(int length)
{
    struct IntArray *ar;
    ar = (struct IntArray *)malloc(sizeof(struct IntArray));
    ar->length = length; 
    ar->dataPtr = (int *)malloc(ar->length*sizeof(int));
    for(int i=0; i<ar->length;i++)
    {
        ar->dataPtr[i] = 0;
    }
    return ar;
}
/* create a struct intarray pointer ar. Set ar = struct intarray * and use malloc for the size of intarray. Set ar->length equal to length and dataPtr of ar is equal to int * and use malloc for length of ar*sizeof int. Use a for loop from i = 0 to i is less than length of ar and set dataPtr index i of ar equal to 0. return ar. */

void freeIntArray(struct IntArray **arrayPtr)
{
    free((*arrayPtr)->dataPtr);
    (*arrayPtr)->dataPtr = NULL;
    (*arrayPtr)->length = 0;
    free(*arrayPtr);
    (*arrayPtr) = NULL;
}
/*call free on dataPtr of arrayPtr. Set dataPtry of arrayPtr equal to NULL and length of arrayPtr equal to 0. Call free on *arrayPtr and then set *arrayPtr to NULL */

void readIntArray(struct IntArray *array)
{
    for(int i = 0; i < array->length;i++)
        {
        printf("Enter int: ");
        array->dataPtr[i] = getInt();
        }

}
/*use a for loop from i = 0 to i is less than length of array. In the for loop have a print statement which prompts user and then set index i dataPtr of array equal to the call of getInt.*/

void swap(int *xp, int *yp)
{
    int tempx = *xp;
    *xp = *yp;
    *yp = tempx;
}
/*set int of tempx equal to pointer xp. Set *xp equal to *yp and then *yp equal to tempx. Using tempx will keep *xp from being changed to *yp before completing the swap*/

void sortIntArray(struct IntArray *array)
{
   for(int i = 0;i<array->length-1;i++)
    {
        for(int j = 0; j<array->length-1-i;j++)
        {
            if((array->dataPtr)[j] > (array->dataPtr)[j+1])
            {
                swap((array->dataPtr)+j, (array->dataPtr)+j+1);
            }
        }
    }
}
/*use for loop from i = 0 to i is less than length-1 of array. Put another for loop inside of this from j =0 to j is less than legnth - 1 -i of array. Then if dataPtry of array index j is greater than index at j+1 then call swap function*/

void printIntArray(struct IntArray *array)
{
    printf("[");
    for(int i = 0; i < array->length; i++)
    {
        printf("%d", (array->dataPtr)[i]); 
        if(i < (array->length)-1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
/*print an open brace. Then use a for loop from i=0 to i is less than length of array. Then print dataPtr of array at index i. If i is less than length-1 of array then print comma and space. Then outside of for loop print closing brace and new line*/

int main(int argc, char *argv[]){
    printf("Enter length: ");
    int length = getInt();
    struct IntArray* ar = mallocIntArray(length);
    readIntArray(ar);
    sortIntArray(ar);
    printIntArray(ar);
    freeIntArray(&ar);
    return 0;         
}
