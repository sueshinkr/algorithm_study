#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
	int	key;
	struct	binary_tree *left;
	struct	binary_tree *right;
}	tree;

static void	postorder(tree *cur)
{
	if (cur->left)
		postorder(cur->left);
	if (cur->right)
		postorder(cur->right);
	printf("%d\n", cur->key);
}

int	main()
{
	int	key;

	tree	*root = NULL;
	tree	*temp;

	while(1)
	{
		int check = scanf("%d", &key);
		if (check == EOF)
			break;

		tree *new = (tree *)malloc(sizeof(tree));
		new->key = key;
		new->left = NULL;
		new->right = NULL;

		if (!root)
			root = new;
		else
		{
			temp = root;
			while(temp)
			{
				if (temp->right)
					temp = temp->right;
				else if (key > temp->key)
				{
					temp->right = new;
					break;
				}
				else if (temp->left)
					temp = temp->left;
				else if (key < temp->key)
				{
					temp->left = new;
					break;
				}
			}
		}	
	}

	postorder(root);
	return (0);
}


/*
#include <stdio.h>

#define NODE_MAX_SIZE	10000

int tree[NODE_MAX_SIZE];
int n = 0;

void PostOrder(int root, int start, int end)
{
	int sep = start;	// separator
	if(root != end){
		while(sep <= end){
			if(tree[root] < tree[sep])	break;
			
			sep++;
		}
		
		if(start != sep){	// left subtree
			PostOrder(start, start+1, sep-1);
		}
	
		if(end != sep-1){	// right subtree
			PostOrder(sep, sep+1, end);
		}
	}
	
	printf("%d\n", tree[root]);
}

int main(void)
{
	int value;
	while(scanf("%d", &value) != EOF){
		tree[n++] = value;
	}
	
	PostOrder(0, 1, n-1);
	
	return 0;
}
*/