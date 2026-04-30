/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#include "avl_balance.h"

int balance(struct node *n)
{
	int height_left, height_right;
	height_left = n && n->left ? n->left->height : 0;
	height_right = n && n->right ? n->right->height : 0;

	return height_left - height_right;
}
