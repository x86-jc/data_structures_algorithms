/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#include "avl_insert.h"

struct node *insert(struct node *n, int key)
{
	struct node *node = NULL;

	if(n == NULL)
	{
		node = (struct node *)malloc(sizeof(struct node));
		node->data = key;
		node->height = 1;
		node->left = node->right = NULL;

		return node;
	}

	if(key < n->data)
	{
		n->left = insert(n->left, key);
	}
	else if(key > n->data)
	{
		n->right = insert(n->right, key);
	}

	n->height = node_height(n);

	if(balance(n) == 2 && balance(n->left) == 1)
	{
		return left_left_rotation(n);
	}
	else if(balance(n) == 2 && balance(n->left) == -1)
	{
		return left_right_rotation(n);
	}
	else if(balance(n) == -2 && balance(n->right) == -1)
	{
		return right_right_rotation(n);
	}
	else if(balance(n) == -2 && balance(n->right) == 1)
	{
		return right_left_rotation(n);
	}

	return n;
}
