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
