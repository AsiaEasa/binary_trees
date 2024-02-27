#include "binary_trees.h"

int get_successor(avl_t *node);
int replace_with_successor(avl_t *root);
int remove(avl_t *node);
avl_t *avl_remove(avl_t *root, int value);

/**
 * get_successor - Get the minimum value in the right subtree.
 * @node: The node to start the search.
 * Return: The minimum value.
 */
int get_successor(avl_t *node)
{
	int L;

	if (!node)
		return (0);

	L = get_successor(node->left);
	return (L == 0 ? node->n : L);
}

/**
 * replace_with_successor - Replace the node value with its successor.
 * @root: The node with two children.
 * Return: The value of the successor.
 */
int replace_with_successor(avl_t *root)
{
	int NEW;

	NEW = get_successor(root->right);
	root->n = NEW;
	return (NEW);
}

/**
 * remove - Remove a node based on its children.
 * @node: The node to remove.
 * Return: 0 if no children, or other value if it has.
 */
int remove(avl_t *node)
{
	avl_t *child;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		child = node->left ? node->left : node->right;

		if (node->parent->right == node)
			node->parent->right = child;
		else
			node->parent->left = child;

		child->parent = node->parent;
		free(node);
		return (0);
	}
	else
		return (replace_with_successor(node));
}

/**
 * avl_remove - Remove a node from a BST tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int XX;

	if (!root)
		return (NULL);

	if (value < root->n)
		avl_remove(root->left, value);
	else if (value > root->n)
		avl_remove(root->right, value);
	else if (value == root->n)
	{
		XX = remove(root);
		if (XX != 0)
			avl_remove(root->right, XX);
	}
	return (root);
}
