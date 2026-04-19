/********************************************************
 * Title: 		Basic trie								*
 * Creator: 		John J. Coleman						*
 * Creation Date:	19.04.2026							*
 * Modified Date:	19.04.2026							*
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256

typedef struct trie_node
{
	// lookup table of pointers to chars
	struct trie_node *child[NUM_CHARS];
	bool terminal;
} trie_node;

trie_node *create_node()
{
	trie_node *node = malloc(sizeof *node);

	for(int i = 0; i < NUM_CHARS; i++)
	{
		node->child[i] = NULL;
	}

	node->terminal = false;
	return node;
}

bool trie_insert(trie_node **root, char *signed_text)
{
	if(*root == NULL)
	{
		*root = create_node();
	}

	unsigned char *text = (unsigned char *)signed_text;

	trie_node *tmp = *root;
	int length = strlen(signed_text);

	for(int i = 0; i < length; i++)
	{
		if(tmp->child[text[i]] == NULL)
		{
			// create new node
			tmp->child[text[i]] = create_node();
		}

		tmp = tmp->child[text[i]];
	}

	if(tmp->terminal)
	{
		return false;
	}
	else
	{
		tmp->terminal = true;
		return true;
	}
}

void print_trie_recursive(trie_node *node, unsigned char *prefix, int length)
{
	unsigned char new_prefix[length + 2];
	memcpy(new_prefix, prefix, length);
	new_prefix[length + 1] = 0;

	if(node->terminal)
	{
		printf("Word: %s\n", prefix);
	}

	for(int i = 0; i < NUM_CHARS; i++)
	{
		if(node->child[i] != NULL)
		{
			new_prefix[length] = i;
			print_trie_recursive(node->child[i], new_prefix, length + 1);
		}
	}
}

void print_trie(trie_node *root)
{
	if(root == NULL)
	{
		printf("trie empty.\n");
		return;
	}

	print_trie_recursive(root, NULL, 0);
}

bool search_trie(trie_node *root, char *signed_text)
{
	unsigned char *text = (unsigned char *)signed_text;
	int length = strlen(signed_text);
	trie_node *tmp = root;

	for(int i = 0; i < length; i++)
	{
		if(tmp->child[text[i]] == NULL)
		{
			return false;
		}

		tmp = tmp->child[text[i]];
	}

	return tmp->terminal;
}

bool node_has_children(trie_node *node)
{
	if(node == NULL)
		return false;

	for(int i = 0; i < NUM_CHARS; i++)
	{
		if(node->child[i] != NULL)
		{
			return true;
		}
	}

	return false;
}

trie_node *delete_string_recursive(trie_node *node, unsigned char *text, bool *deleted)
{
	if(node == NULL)
		return node;

	if(*text == '\0')
	{
		if(node->terminal)
		{
			node->terminal = false;
			*deleted = true;

			if(node_has_children(node) == false)
			{
				free(node);
				node = NULL;
			}
		}

		return node;
	}

	node->child[text[0]] = delete_string_recursive(node->child[text[0]], text + 1, deleted);
	if(*deleted && node_has_children(node) == false && node->terminal == false)
	{
		free(node);
		node = NULL;
	}

	return node;
}

bool delete_string(trie_node **root, char *signed_text)
{
	unsigned char *text = (unsigned char *)signed_text;
	bool result = false;

	if(*root == NULL)
		return false;

	*root = delete_string_recursive(*root, text, &result);
	return result;
}

int main(int argc, char *argv[])
{
	trie_node *root = NULL;

	trie_insert(&root, "snickers");
	trie_insert(&root, "reeses");
	trie_insert(&root, "dots");
	trie_insert(&root, "musketeer");
	trie_insert(&root, "musket");

	print_trie(root);

	printf("\nSearching for dots: %d\n", search_trie(root, "dots"));
	printf("Searching for snickers: %d\n\n", search_trie(root, "snickers"));

	delete_string(&root, "dots");
	delete_string(&root, "reeses");

	print_trie(root);

	return 0;
}
