---
title: "Polynomial addition using circular linked lists"
tags: ""
---

```c
//Polynomial addition through circular linked lists
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct  poly{
    int cf,px,py,pz;
    struct poly *link;
};
typedef struct poly *P;
P getnode(){
    P x;
    x=(P)malloc(sizeof(struct poly));
    if(x==NULL){
        printf("Memory not available\n");
        exit(0);
    }
    return x;
}
void read_poly(P p1,int n){
    P temp,next;
    for(int i=0;i<n;i++){
        temp=getnode();
        printf("Enter the cf px py pz of term %d\n",i+1);
        scanf("%d%d%d%d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        next=p1->link;
        p1->link=temp;
        temp->link=next;  ///points to first

    }
}
void display(P head){
    P cur;
    printf("Elements of polynomial:\n");
    cur=head->link;
    while (cur!=head)
    {
        if(cur->cf>=0)
            printf("+%dx^%dy^%dz^%d ",cur->cf,cur->px,cur->py,cur->pz);
        else
            printf("%dx^%dy^%dz^%d ",cur->cf,cur->px,cur->py,cur->pz);
        cur=cur->link;
    }
    printf("\n");
    
}
P compare(P term,P p2){
    P cur=p2->link;
    while (cur!=p2)
    {
        if((cur->px==term->px)&&(cur->py==term->py)&&(cur->pz==term->pz)){
            return cur;
        }
        cur=cur->link;
    }
    return NULL;
    
}
void insert_front(P head,int cf,int px,int py,int pz ){
    P temp=getnode();
    temp->cf=cf;temp->px=px;temp->py=py;temp->pz=pz;
    P next=head->link;
    head->link=temp;
    temp->link=next;  ///points to first
        
}
int evaluate(P p1){                 //Evaluation of a polynomial
    int sum=0,x,y,z;
    P cur=p1->link;
    printf("enter the value of x y z:");
    scanf("%d%d%d",&x,&y,&z);
    while (cur!=p1)
    {
        /* code */
        sum=sum+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
        cur=cur->link;
    }
    return sum;
}
int main(){
    P p1,p2,res;    
    int n1,n2;
    p1=getnode();
    p1->link=p1;
    p2=getnode();
    p2->link=p2;
    res=getnode();
    res->link=res;
    printf("Enter number of terms for p1: ");
    scanf("%d",&n1);
    read_poly(p1,n1);
    display(p1);
    printf("Enter numbeer of terms for p2:");
    scanf("%d",&n2);
    read_poly(p2,n2);
    display(p2);
    //Iteratig over 1st list
    P cur=p1->link;
    P addr;
    while (cur!=p1)
    {
        addr=compare(cur,p2);
        if(addr==NULL){
            insert_front(res,cur->cf,cur->px,cur->py,cur->pz);
        }
        else{
            insert_front(res,cur->cf+addr->cf,cur->px,cur->py,cur->pz);
            addr->cf=-999;
        }
        cur=cur->link;
    }
    // Iterating over 2nd list
    P mov=p2->link;
    while (mov!=p2)
    {
        if(mov->cf!=-999){
            insert_front(res,mov->cf,mov->px,mov->py,mov->pz);
        }
        mov=mov->link;
    }
    display(res);
    printf("\nAnswer %d",evaluate(res));
}
```
