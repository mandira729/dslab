#include<stdio.h>
#include<stdlib.h>

struct node {
char ssn[20],name[20],dept[20],desig[20],ph[20];
int sal;
struct node *llink,*rlink;
};
typedef struct node nd;


nd *insertfront(nd*f) {
    nd *t ;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter ssn name dept desig ph sal\n");
    scanf("%s %s %s %s %s %d",t->ssn,t->name,t->dept,t->desig,t->ph,&(t->sal));
    t->rlink = t->llink = 0;
    if (f!=0) {
        t->rlink=f;
        f->llink=t;
    }
    return t;
}
nd *insertrear(nd*f) {
    nd *l,*t;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter ssn name dept desig ph sal\n");
    scanf("%s %s %s %s %s %d",t->ssn,t->name,t->dept,t->desig,t->ph,&(t->sal));
    t->rlink=t->llink=0;

    if(f==0)
    return t;

    for(l=f;l->rlink!=NULL;l=l->rlink);
    l->rlink=t;
    t->llink=l;
    return f;
}
nd *deletefront(nd*f) {
    
    if(f==0){
        printf("DLL is empty\n");
        return f;
    }
    if(f->rlink==0) {
        free(f);
        return 0;
    }
    f=f->rlink;
    free(f->llink);
    f->llink=0;
    return f;
}
nd * deleterear(nd*f) {
    nd *p,*l;
    if(f==0) {
        printf("Dll is empty\n");
        return 0;
        }
    if (f->rlink==0) {
        free(f);
        return 0 ;
    }
    for(l=f; l->rlink!=NULL; l=l->rlink);
    p=l->llink;
    p->rlink=0;
    free(l);
    return f;
}
nd * create(nd* f) {
    int n;
    printf("Enter the value of n");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        f=insertrear(f);

    return f;
}
        
 void display(nd *f) {
     int cnt=0;
     if(f==0) {
         printf("Dll is empty");
         return ;

     }

     nd *curr = f;
     printf("contents of Dll are \n"); 
     for(;curr!=0; curr=curr->rlink, cnt++) {
         printf("%s %s %s %s %s %d\n\n",curr->ssn,curr->name,curr->dept,curr->desig,curr->ph,(curr->sal) );
         

     }
     printf("Number of nodes %d\n",cnt);
 }   

int main() {
    nd* first=0;
    int ch;
    while(1) {
        printf("1.create\n2.display\n3.insertfront\4.insertrear\n5.deletefront\n6.deleterear\n7.exit\n\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: first=create(first);break;
            case 2: first=insertfront(first); break;
            case 3: first=insertrear(first);break;
            case 4: first=deletefront(first); break;
            case 5: first=deleterear(first); break;
            case 6: display(first); break;
            case 7: exit(0);

        }
    }
}
