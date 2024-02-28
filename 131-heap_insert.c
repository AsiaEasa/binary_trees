#include "binary_trees.h"
#include "0-binary_tree_node.c"
/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{ heap_t *new_node, *CC;

	if (!root || !value)
		return (NULL);

	if (!(*root))
	{ new_node = binary_tree_node(NULL, value);
		if (!(new_node))
			return (NULL);
		*root = new_node;
		return (new_node); }
	CC = *root;

	while (1)
	{
		if (value < CC->n)
		{
			if (!(CC->left))
			{
				new_node = binary_tree_node(CC, value);
				if (!new_node)
					return (NULL);
				CC->left = new_node;
				return (new_node);
			}
			else
				CC = CC->left; }
		else if (value > CC->n)
		{
			if (!(CC->right))
			{
				new_node = binary_tree_node(CC, value);
				if (!(new_node))
					return (NULL);
				CC->right = new_node;
				return (new_node);
			}
			else
				CC = CC->right; }
		else
			return (NULL); }
	return (NULL); }
