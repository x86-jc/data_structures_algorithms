/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#ifndef AVL_ROTATION_H
#define AVL_ROTATION_H

#include "avl.h"
#include "avl_height.h"

struct node *left_left_rotation(struct node *);
struct node *left_right_rotation(struct node *);
struct node *right_right_rotation(struct node *);
struct node *right_left_rotation(struct node *);

#endif
