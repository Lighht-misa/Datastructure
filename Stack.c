#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct Stack
{
    ElemType data;
    struct Stack *next;
    int top;
}Stack;
void InitStack(Stack*s){
    s = (Stack*)malloc(sizeof(Stack));
    s->top=-1;
    s->next=NULL;

    printf("Inited!\n");
}
void Isempty(Stack*s){
    if(s->top==-1){
        printf("The stack is empty!\n");
    }
}
void InsertStack(Stack*Head,int value)
{
    Stack*s=(Stack*)malloc(sizeof(Stack));
    s->data = value;
    s->next = Head->next;
    Head->next =s;
    Head->top++;
}
void PopStack(Stack*Head){
    if(Head->top==-1){
        printf("The stack is empty!\n");
        return;
    }
    Stack*s=Head->next;
    Head->next= Head->next->next;
    Head->top--;
    free(s);
}
void Getlength(Stack*Head)
{
    Stack*s = Head;
    int length=0;
    while(s->next!=NULL){
        s=s->next;
        length++;
    }
    printf("The length is %d\n",length);
}
void GetPop(Stack*Head){
    if(Head->top==-1){
        printf("The stack is empty!\n");
        return;
    }
    printf("%d\n",Head->next->data);
}
int main(){
    // Stack *s = (Stack*)malloc(sizeof(Stack));
    // InitStack(s);
    // InsertStack(s,10);
    // InsertStack(s,20);
    // InsertStack(s,30);
    // InsertStack(s,40);
    // GetPop(s);
    // int *value = (int*)malloc(sizeof(int));
    // PopStack(s,value);
    // GetPop(s);
    // PopStack(s,value);
    // GetPop(s);
    //顺序table的实现
    Stack*Head=(Stack*)malloc(sizeof(Stack));
    InitStack(Head);
    InsertStack(Head,10);
    InsertStack(Head,20);
    InsertStack(Head,30);
    InsertStack(Head,40);
    InsertStack(Head,50);
    GetPop(Head);
    GetPop(Head);
    printf("\n\n");
    PopStack(Head);
    PopStack(Head);
    GetPop(Head);
    return 0;
}