// SCLL with header for polynomial addition.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly
{
	int c, x, y, z;
	struct poly *next;
};

typedef struct poly *NODE;

NODE getnode()
{
	NODE x = (NODE) malloc(sizeof(struct poly));
	if (!x)
		exit(0);
	return x;
}

void displaypoly(NODE head)
{
	NODE curr = head->next;
	while(curr != head)
	{
		if (curr->c >= 0)
			printf("+ %d(x^%d)(y^%d)(z^%d) ", curr->c, curr->x, curr->y, curr->z);
		else
			printf(" %d(x^%d)(y^%d)(z^%d) ", curr->c, curr->x, curr->y, curr->z);
		
		curr = curr->next;
	}
	printf("\n");
}

NODE insertfront(NODE head, NODE new)
{
	new->next = head->next;
	head->next = new;
	return head;
}

void createpoly(NODE head)
{
	int n;
	printf("Enter the number of terms : ");
	scanf("%d", &n);
	
	while (n--)
	{
		NODE new = getnode();
		printf("Enter the coeff, px, py and pz respectively : ");
		scanf("%d %d %d %d", &new->c, &new->x, &new->y, &new->z);
		// new->next = NULL;

		insertfront(head, new);
	}
	printf("\nPolynomial saved\n");
}


void solvePolynomial(NODE head)
{
	int vx, vy, vz;
	printf("Enter the values of x, y and z respectively : ");
	scanf("%d %d %d", &vx, &vy, &vz);
	
	float ans = 0;
	NODE curr = head->next;
	
	while (curr != head)
	{
		ans += (curr->c*pow(vx,curr->x)*pow(vy, curr->y)*pow(vz, curr->z));
		curr = curr->next;
	}
	
	printf("\nThe solution of this polynomial is %f\n", ans);
}

void addpoly(NODE sum, NODE p1, NODE p2)
{
	NODE pc1, pc2;
	pc1 = p1->next;

	while (pc1 != p1)
	{
		pc2 = p2->next;

		while (pc2 != p2)
		{
			if (pc2->x == pc1->x && pc2->y == pc1->y && pc2->z == pc1->z)
			{
				NODE new = getnode();
				new->c = pc2->c + pc1->c;
				new->x = pc1->x;
				new->y = pc1->y;
				new->z = pc1->z;
				insertfront(sum, new);
				pc2->c = -999;
				break;
			}
			pc2 = pc2->next;
		}

		if (pc2 == p2)
		{
			NODE new = getnode();
			new->c = pc1->c;
			new->x = pc1->x;
			new->y = pc1->y;
			new->z = pc1->z;
			insertfront(sum, new);
		}

		pc1 = pc1->next;
	}
	pc2=p2->next;
	while (pc2 != p2)
	{
		if (pc2->c != -999)
		{
			NODE new = getnode();
			new->c = pc2->c;
			new->x = pc2->x;
			new->y = pc2->y;
			new->z = pc2->z;
			insertfront(sum, new);
		}
		pc2=pc2->next;
	}
}
		
		

int main()
{
	int ch, n;
	NODE p1 = getnode(), p2 = getnode(), psum = getnode();
	p1->next = p1;
	p2->next = p2;
	psum->next = psum;

	while(1)
	{
		printf("\n1. Solve a Polynomial\n2. Add two polynomials\nChoice : ");
		scanf("%d", &n);

		switch(n)
		{
			case 1:		printf("Enter the polynomial : ");
						createpoly(p1);
						displaypoly(p1);
						solvePolynomial(p1);
						break;

			case 2: 	printf("\nEnter polynomial 1: ");
						createpoly(p1);
						displaypoly(p1);
						printf("\nEnter polynomial 2: ");
						createpoly(p2);
						displaypoly(p2);
						addpoly(psum, p1, p2);
						printf("\nThe resultant polynomial is : ");
						displaypoly(psum);
						break;

			default: 	return 0;
		}
	}	
}
		
			
	
	
	
	
	
	
	
	
	
	
	














; 










