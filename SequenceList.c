#include <stdio.h>
#define MAXSIZE 100

typedef struct SequenceList
{
    int data[MAXSIZE];
    int length;
}SequenceList;
void InitLise(SequenceList *L){
    L->length = 0;
    for (int i =0;i<L->length;i++){
        printf("Is initing...\n");
        L->data[i]=0;
    }
}
void Insert(SequenceList*L,int index,int value){
    if(index < 0 || index > L->length){
        return ;
    }
    for(int i = L->length ;i > index;i--){//The error place is that I worte "i = L.length-1",,but when the length ==0 then
        //i== -1 and then caused undefine behaviour.
        //and I worte the error "i <= index " because obsviously that L->length is > index
        L->data[i] = L->data[i-1];
    }
    L->data[index] = value;
    L->length++;
}
void Delete(SequenceList*L,int index){
    if(L->length ==0){
        printf("The list is empty!\n");
        return;
    }
    if(index < 0 || index >L->length){
        printf("The index is error!\n");
    }
    for(int i = index;i < L->length-1;i++){
        L->data[i] = L->data[i+1];
        //The error palce is that I wrote "i >= L->length" then the index must be < L->length,it will never works
    }
    L->length--;
}

int main(){
    SequenceList l;
    InitLise(&l);
    for(int i =0;i<100;i++){
    Insert(&l,i,i+1);
    }
    for(int i =0;i<100;i++){
    printf("The value is %d\n",l.data[i]);
    }
    Delete(&l,50);
      for(int i =0;i<100;i++){
    printf("The value is %d\n",l.data[i]);
    }
    return 0;
}