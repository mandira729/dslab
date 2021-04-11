//BST

//Create bst of N integers
#include <stdio.h>
#include <stdlib.h>


struct node
{
	int val;
	struct node *left, *right;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE x = (NODE) malloc(sizeof(struct node));
	if (!x)
		exit(0);
	return x;
} 

NODE insert(NODE root, NODE new)
{
	if (root == NULL)
		return new;
	
	else if (new->val < root->val)
		root->left = insert(root->left, new);
	else if (new->val > root->val)
		root->right = insert(root->right, new);
	
	else
		return root;		
}
	
	
	
	
	
	
NODE create_bst(NODE root)
{
	int n, x;
	
	printf("Enter the number of elements to be inserted : ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		printf("Enter %dth element : ", i);
		scanf("%d", &x);
		NODE new = getnode();
		new->val = x;
		new->left = NULL;
		new->right = NULL;
			
		root = insert(root, new);
	
	}

	return root;
}
	
	
void inorder(NODE root)
{
	if (root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void preorder(NODE root)
{
	if (root == NULL)
		return;
		
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(NODE root)
{
	if (root == NULL)
		return;
		
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

void search(NODE root, int n)
{
	NODE curr = root;
	
	while (curr != NULL)
	{
		if (curr->val == n)
		{
			printf("\nValue exists in the tree.");
			return;
		}
		else if (n < curr->val)
			curr = curr->left;
		else
			curr = curr->right;
	}
	
	printf("\nThe value was not found!");
}
		

NODE delete(NODE root, int target)
{
    if (root == NULL)
    {
        printf("The tree is empty!\n");
        return root;
    }

    // Get to the target while saving the parent;
    NODE curr = root, parent = NULL;
    while(curr != NULL)
    {
        if (curr->val == target)
            break;

        parent = curr;
        
        if (target < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
    {
        printf("The target is unavailable in this tree\n");
        return root;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        if (parent == NULL)
            return NULL;

        if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;

        free(curr);
        return root;      
    }
    
    NODE successor;

    if (curr ->left == NULL || curr->right == NULL)
    {
        if (curr->left == NULL)
            successor = curr->right;
        else
            successor = curr->left;

        if (parent == NULL)
        {
            free(curr);
            return successor;
        }

        if (parent->left == curr)
            parent->left = successor;
        else
            parent->right = successor;

        free(curr);
        return root;
    }

    NODE pos_del = curr, min_parent = curr;
    curr = curr->right;
    while(curr->left != NULL)
    {
        min_parent = curr;
        curr = curr->left;
    }

    successor = curr->right; // can either be right subtree or NULL
    if (min_parent->left == curr)
        min_parent->left = successor;
    else
        min_parent->right = successor;

    pos_del->val = curr->val;
    free(curr);
    return root;
}
		
		

int main()
{
	NODE root = NULL;
	
	int ch, n;
	
	while(1)
	{
		printf("\n1. Create BST of N numbers\n2. Inorder\n3. Preorder\n");
		printf("4. PostOrder\n5. Search for a key\n6. Delete\nExit by any other key ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: root = create_bst(root);
					break;
			
			case 2: inorder(root);
					printf("\n");
					break;
			
			case 3: preorder(root);
					printf("\n");
					break;
			
			case 4: postorder(root);
					printf("\n");
					break;
			
			case 5: printf("Enter the element to search : ");
					scanf("%d", &n);
					search(root, n);
					break;

			case 6: printf("Enter the element to delete : ");
					scanf("%d", &n);
					delete(root, n);
					break;
			
			default: return 0;	
		}
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
