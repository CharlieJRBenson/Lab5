//Implementation of stack

#include <stdio.h>
#include<stdlib.h>

//declaring structure
struct stack
{
   int data;
   struct stack *nextPtr; //pointer type of stack
};

typedef struct stack Stack;
typedef Stack *thisPtr;

//function prototypes of different functions
void push(thisPtr *top, int x); //for pushing value in stack
int pop(thisPtr *top); //for popping value out of stack
int checkEmpty(thisPtr top); //checking whether stack is empty
void printValue(thisPtr showPtr); //for printing value that are pushed and popped

int main()
{
   thisPtr stackNewPtr = NULL; //declared pointer that points to the top of stack
   int option; //variable for choosing different options
   int value; //variable for storing entered by the user

   //different options for the user
   printf("\nPlease choose following options:\n");
   printf("1. PUSH\n");
   printf("2. POP\n");
   printf("3. EXIT\n");

   scanf("%d", &option);

   //program flow enters while loop if user enter value other than 3
   while (option != 3)
   {
      switch (option)
      {
      case 1:
         printf("\nEnter value: ");
         scanf("%d", &value);
         push(&stackNewPtr, value);
         printValue(stackNewPtr);
         break;

      case 2:
         if (!checkEmpty(stackNewPtr))
         {
            printf("\nPopped Value: %d\n", pop(&stackNewPtr));
         }
         printValue(stackNewPtr);
         break;

      default:
         puts("\n**Invalid choice**");
         break;
      }

      printf("\nWhat do you want: ");
      scanf("%d", &option);
   }
}

//function for pushing value into the top of stack
void push( thisPtr *top, int x )
{
    thisPtr nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(Stack));

    //pushing value at the top of stack only if there is space
    if(nodePtr != NULL)
    {
       nodePtr -> data = x;
       nodePtr -> nextPtr = *top;
       *top = nodePtr;
    }

    else
       printf("\nERROR !!! (Not enough space)");
   }

//popping value out of the stack
int pop(thisPtr *top)
{
   int pValue; //variable for value at the top
   thisPtr tempPtr; //temporary pointer

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> nextPtr;
   free(tempPtr); //free temporary pointer value
   return pValue;
}

//function for printing value stored in the stack
void printValue(thisPtr showPtr)
{
   if(showPtr == NULL)
   {
       printf("\nNo value found.");
   }
   else
   {
      printf("\nData stored in stack:\n");

      while(showPtr != NULL)
     {
         printf("%d --> ", showPtr -> data);
         showPtr = showPtr -> nextPtr;
     }
     printf("NULL\n");
   }
}

int checkEmpty(thisPtr top)
{
   return top == NULL;
}