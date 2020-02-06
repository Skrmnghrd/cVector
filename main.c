/*  A simple module for vector implementation in C: */
#include <stdio.h>
#include <stdlib.h>

//function declarations
/* 
Todo: Make an option ot craete arrays with diffenret data types as well.
*/

typedef struct 
{
    int *array; //the actual freaking array
    int size;
    int capacity;
} Array;

//creates new array with (ptr array, size and capacity)
void initialize_array(Array *a, int size, int capacity)
{
    a->array = (int * ) malloc (size * sizeof(int)); 
    a->capacity = capacity;
    a->size = size;
    //init an array with the size 
}

//pushes the value to the last element of the array
void push_last(Array *a, int value)
{
    
    //pushes at the last index of the array for now
    printf("Current Size:%d, Current Capacity:%d\n", a->size, a->capacity);
    if (a->size == a->capacity)
    {
        printf("Adjusting size!\n");
        a->size *= 2;
        
        int* tmp_ptr = (int *) realloc(a->array, a->size * sizeof(int) );
        //if the size is equal to the capacity, then add space
        if (tmp_ptr == NULL)
        {
            //tmp_ptr == NULL means smth went wrong with alloc
            free(tmp_ptr);
            exit(1); //bad prac, chng
        }
        else
        {
            //if all went well then assign new chucnk to old pointer
            a->array = tmp_ptr;
            //and assign values :)
            a->array[a->capacity] = value;
            a->capacity += 1;
        }
        free(tmp_ptr); //clean this bad boiii up
    }
    else //if the array has a space then
    {
        a->array[a->capacity] = value;
        a->capacity += 1; //add one to the capacity
    }
}

int main(void) //it's never the same without void
{
    const int INITIAL_SIZE = 1;
    
    Array test;
    initialize_array(&test, INITIAL_SIZE, 0);
    for(int i = 0; i < 501; i++)
    {
        push_last(&test, i);
    }
    for (int i=0; i<501; i++)
    {
        printf("%d\n", test.array[i]);
    }
}




