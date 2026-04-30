/************************************************
 * Title:               avl                     *
 * Creator:             John J. Coleman         *
 * Creation Date:       2026.04.28              *
 * Modified Date:       2026.04.29              *
 *                                              *
 * Description:                                 *
 * AVL tree example.                            *
 ************************************************/

#include "avl.h"
#include "avl_balance.h"
#include "avl_insert.h"
#include "avl_height.h"
#include "avl_rotation.h"

/*
struct node
{
        struct node *left;
        struct node *right;
        int data;
        int height;
} *root = NULL;
*/

int main(int argc, char *argv[])
{
        struct node *test1 = malloc(sizeof(struct node));
        struct node *test2 = malloc(sizeof(struct node));

        test1 = insert(test1, 10);
        insert(test1, 5);
        insert(test1, 2);

        test2 = insert(test2, 50);
        insert(test2, 10);
        insert(test2, 20);

        free(test1);
        free(test2);

        return 0;
}
