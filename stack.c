#include <stdio.h>

 
int top = -1;
struct stackNode
{
    int nodeData;
    struct stackNode *nextPtr;    
};


int isempty(struct stackNode top) {
    //boolean
   if(top.nodeData == NULL)
      return 1;
   else
      return 0;
}


struct stackNode pop(struct stackNode top, struct stackNode first) {
    
    printf("%d",top.nextPtr->nodeData);
    if(top.nextPtr == NULL){
        
    }

    return top;
}

struct stackNode push(struct stackNode top, int data){
   top = top.nextPtr; 
   top.nodeData = data;

   return top;
}

int printStack(){

    while (/* condition */)
    {
        /* code */
    }
    
}

int main() {
    //creates first and last node pointers
   struct stackNode first; 
   struct stackNode top = push(first, 5);

   return 0;
}