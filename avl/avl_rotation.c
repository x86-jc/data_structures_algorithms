/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#include "avl_rotation.h"

struct node *left_left_rotation(struct node *n)
{
	struct node *left_node = n->left;
	struct node *left_node_right_spawn = left_node->right;
	
	left_node->right = n;
	n->left = left_node_right_spawn;
	n->height = node_height(n);
	left_node->height = node_height(left_node);
	
	if(root == n)
	{
		root = left_node;
	}
	
	return left_node;
}

struct node *left_right_rotation(struct node *n)
{
	struct node *left_node = n->left;
	struct node *left_node_right_spawn = left_node->right;

	left_node->right = left_node_right_spawn->left;
	n->left = left_node_right_spawn->right;
	left_node_right_spawn->left = left_node;
	left_node_right_spawn->right = n;

	left_node->height = node_height(left_node);
	n->height = node_height(n);
	left_node_right_spawn->height = node_height(left_node_right_spawn);

	if(root == n)
	{
		root = left_node_right_spawn;
	}

	return left_node_right_spawn;
}
