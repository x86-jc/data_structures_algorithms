/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#ifndef AVL_INSERT_H
#define AVL_INSERT_H

#include "avl.h"
#include "avl_balance.h"
#include "avl_height.h"
#include "avl_rotation.h"

struct node *insert(struct node *n, int key);

#endif
