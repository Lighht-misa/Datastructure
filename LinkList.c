#include <stdio.h>
#include <stdlib.h>
typedef  int Elem ;
typedef struct LNode
{
    Elem data;
    struct LNode* next;
}LNode;
void InitList(LNode*Head){
    Head->data = 0;
    Head->next = NULL;
    printf("Inited!\n");
}
void InsertTail(LNode*Head,int value){
    if(Head->next == NULL){
        LNode*s = (LNode*)malloc(sizeof(LNode));
        s->data = value;
        Head->next = s;
        s->next=NULL;
        return;
    }
    while(Head->next!=NULL){
        Head = Head->next;
    }
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data = value;
    Head->next =s;
    s->next = NULL;
}
void InsertHead(LNode*Head,int value){
    LNode*s=(LNode*)malloc(sizeof(LNode));
    s->data = value;
    s->next = Head->next;
    Head->next = s;
}
void InsertIndex(LNode*Head,int index,int value){
    LNode* p =Head;
    int position = 0;
    while(p!=NULL && position<index -1){
        p = p->next;
        position++;
    }
    LNode*s=(LNode*)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
}
void DeleteTail(LNode*Head){
    if(Head->next == NULL){
        return;
    }
    LNode*p = Head;
    LNode*prev = NULL;
    while(p->next!=NULL){
        prev = p;
        p = p->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    free(p);
    }
}
void DeleteHead(LNode*Head){
    if(Head->next==NULL){
        return;
    }
    LNode*p = Head->next;
    Head->next = p->next;
    free(p);
}
void DeleteIndex(LNode*Head,int index){
    LNode*p = Head;
    LNode*prev= NULL;
    int pos = 0;
    while(p->next!=NULL && pos < index - 1){
        prev = p;
        p=p->next;
        pos++;
    }
    if(prev != NULL){
        prev->next = p->next;
        free(p);
    }
}
int Getvalue(LNode*Head,int position){
    LNode*p = Head->next;
    int count = 1;
    while(p!=NULL && count<position){
        p = p->next;
        count++;
    }
    if(p!=NULL){
        return p->data;
    }
}
int GetLength(LNode*Head){
    int i = 0;
    while(Head->next!= NULL){
        Head = Head->next;
        i++;
    }
    return i;
}
int main(){
    LNode *Head =(LNode*)malloc(sizeof(LNode));
    InitList(Head);
    int n1 = 10;
    InsertTail(Head,n1);
    InsertTail(Head,n1);
    InsertTail(Head,n1);
    int n2 = 5;
    InsertHead(Head,n2);
    InsertHead(Head,n2);
    InsertHead(Head,n2);
    InsertIndex(Head,4,8);
    InsertIndex(Head,5,9);
    InsertIndex(Head,6,100);
    DeleteTail(Head);
    DeleteHead(Head);
    DeleteIndex(Head,2);
    int count2 = GetLength(Head);
        for(int i =1;i<=count2;i++){
        int value = Getvalue(Head,i);
        printf("The index %d's value is %d\n",i,value);
    }
    return 0;
}