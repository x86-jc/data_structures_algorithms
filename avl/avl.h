/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#ifndef AVL_H
#define AVL_h

#include <stdio.h>
#include <stdlib.h>

struct node
{
        struct node *left;
        struct node *right;
        int data;
        int height;
};

#endif
