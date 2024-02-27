#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	/* Update balance factor and check for rotations */
	int balance = binary_tree_balance(*tree);

	/* Left Left Case */
	if (balance > 1 && value < (*tree)->left->n)
		return binary_tree_rotate_right(*tree);

	/* Right Right Case */
	if (balance < -1 && value > (*tree)->right->n)
		return binary_tree_rotate_left(*tree);

	/* Left Right Case */
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return binary_tree_rotate_right(*tree);
	}

	/* Right Left Case */
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return binary_tree_rotate_left(*tree);
	}

	return *tree;
}
