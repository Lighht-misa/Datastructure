#include <stdio.h>
#include <stdlib.h>
typedef int Elem;
typedef struct DouLNode
{
    Elem data;
    struct DouLNode *pre;
    struct DouLNode *next;
}DouLNode;

void Init(DouLNode*Head){
    Head->pre=NULL;
    Head->data=0;
    Head->next=NULL;
    printf("Init finished!\n");
}
void InsertHead(DouLNode*Head,int value){
    if(Head->next==NULL){
    DouLNode *s =(DouLNode*)malloc(sizeof(DouLNode));
    s->data = value;
    Head->next= s;
    s->pre = Head;
    s->next=NULL;
    return;
    }
    DouLNode *s =(DouLNode*)malloc(sizeof(DouLNode));
    s->data=value;
    s->next=Head->next;
    s->pre=Head;
    Head->next->pre=s;//一定要先把后继的节点前置指针先指定
    Head->next=s;
}
void InsertIndex(DouLNode*Head,int index,int value){
    if(index < 1){
        return;
    }
    int j=0;
    DouLNode*p =Head;
    while(p!=NULL && j<index){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return;
    }
    DouLNode*s=(DouLNode*)malloc(sizeof(DouLNode));
    s->data = value;
    s->next = p;
    s->pre=p->pre;
    p->pre->next = s;
    p->pre=s;
}
int GetLength(DouLNode*Head){
    DouLNode*p = Head;
    int j=0;
    while(p->next!=NULL){
        p = p->next;
        j++;
    }
    return j;
}
void DeleteHead(DouLNode*Head){
    if(Head->next==NULL){
        return;
    }
    DouLNode*p=Head->next;
    if(p->next==NULL){
        Head->next=NULL;
        free(p);
        return;
    }
    Head->next=Head->next->next;
    Head->next->pre=Head;   
    free(p);
}
void DeleteTail(DouLNode*Head){
    DouLNode*p=Head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->pre->next=NULL;
    p->pre=NULL;
    free(p);
}
void DeleteIndex(DouLNode*Head,int index){
    int length = GetLength(Head);
    if(length<index){
        printf("The index is wrong!\n");
        return;
    }
    int j =0;
    DouLNode*p=Head;
    while(p!=NULL && j<index){
        p = p->next;
        j++;
    }
    
    if(p->next==NULL){
        p->pre->next=NULL;
        free(p);
        return;
    }
    p->pre->next = p->next;
    p->next->pre= p->pre;
    free(p);
}
void DisplayHead(DouLNode*Head){
    int length = GetLength(Head);
    printf("Length is %d\n",length);
    DouLNode*p=Head->next;
    while(p != NULL){
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
}
void DisplayTail(DouLNode*Head){
    DouLNode*p=Head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p->pre!=NULL){
        printf("%d  ",p->data);
        p=p->pre;
    }
    printf("\n");
}
int main(){
    DouLNode Head;
    Init(&Head);
    InsertHead(&Head,10);
    InsertHead(&Head,20);
    InsertHead(&Head,30);
    InsertHead(&Head,40);
    InsertIndex(&Head,2,35);
    InsertIndex(&Head,2,38);
    DisplayHead(&Head);
    printf("\n");
    DeleteHead(&Head);
    DeleteHead(&Head);
    DeleteTail(&Head);
    DeleteTail(&Head);
    DeleteIndex(&Head,2);
    DeleteIndex(&Head,2);
    DisplayHead(&Head);
    return 0;
}