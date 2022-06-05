#include <stdio.h>

typedef struct binary_tree
{
	int	cur;
	int	left;
	int	right;
}	tree;

tree tr[26];

static void	preorder(tree cur_tree)
{
	printf("%c", cur_tree.cur + 'A');
	if (cur_tree.left != -1)
		preorder(tr[cur_tree.left]);
	if (cur_tree.right != -1)
		preorder(tr[cur_tree.right]);
}

static void	inorder(tree cur_tree)
{
	if (cur_tree.left != -1)
		inorder(tr[cur_tree.left]);
	printf("%c", cur_tree.cur + 'A');
	if (cur_tree.right != -1)
		inorder(tr[cur_tree.right]);
}

static void	postorder(tree cur_tree)
{
	if (cur_tree.left != -1)
		postorder(tr[cur_tree.left]);
	if (cur_tree.right != -1)
		postorder(tr[cur_tree.right]);
	printf("%c", cur_tree.cur + 'A');
}

int	main()
{
	int		n, parent, left_child, right_child;
	char	a, b, c;
	scanf("%d\n", &n);

	while (n-- > 0)
	{
		scanf(" %c %c %c", &a, &b, &c);

		parent = a - 'A';
		left_child = b - 'A';
		right_child = c - 'A';

		if (left_child == '.' - 'A')
			left_child = -1;
		if (right_child == '.' - 'A')
			right_child = -1;

		tr[parent].cur = parent;
		tr[parent].left = left_child;
		tr[parent].right = right_child;
	}

	preorder(tr[0]);
	printf("\n");

	inorder(tr[0]);
	printf("\n");

	postorder(tr[0]);

	return (0);
}