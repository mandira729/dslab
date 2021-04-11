/**************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 15
void insert (char[], int *, int *);
void delete (char[], int *, int *);
void display (char[], int, int);
int
main ()
{
  char q[MAX];
  int r = -1,f=0,cnt = 0, ch;
  while (1)
    {
      printf ("1:insert\n 2:delete\n 3:dispay\n 4:exit\n");
      printf ("enter the choice\n");
      scanf ("%d", &ch);
        switch (ch)
    	{
    	case 1:
    	  insert (q, &r, &cnt);
    	  break;
    	case 2:
    	  delete (q, &f, &cnt);
    	  break;
    	case 3:
    	  display (q, f, cnt);
    	  break;
    	default:
    	  exit (0);
    	}


    }
}

void
insert (char q[], int *r, int *cnt)
{
  char ele;
    if ((*cnt) == MAX)
    {
      printf ("cir q iss overflow");
      return;
    }
    (*r) = ((*r) + 1) % MAX;
    printf ("ENter te element\n");
    scanf (" %c", &ele);
    q[*r] = ele;
    (*cnt)++;
}

void
delete (char q[], int *f, int *cnt)
{
  if ((*cnt) == 0)
    {
      printf ("c q is empty\n");
      return;
    }
  printf ("deleted element is %c\n", q[(*f)]);
  (*f) = ((*f) + 1) % MAX;
  (*cnt)--;
}

void
display (char q[], int f, int cnt)
{
  int i,j;
  if ((cnt) == 0)
    {
      printf ("c q is empty\n");
      return;
    }
  printf ("c q contnts are\n");
  for (i = f, j = 0; j < (cnt); j++)
    {
      printf ("%d : %C\n", i, q[i]);
      i = (i + 1) % MAX;
    }
}