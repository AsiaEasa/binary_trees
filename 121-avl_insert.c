#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int BB;

	if (!tree || !value)
		return (NULL);

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree); }

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if (!((*tree)->left))
			return (NULL); }
	else if (value > (*tree)->n)
	{ (*tree)->right = avl_insert(&((*tree)->right), value);
		if (!((*tree)->right))
			return (NULL); }
	else
		return (NULL);
	BB = binary_tree_balance(*tree);

	if (BB > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (BB < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (BB > 1 && value > (*tree)->left->n)
	{ (*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree)); }

	if (BB < -1 && value < (*tree)->right->n)
	{ (*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree)); }
	return (*tree); }
