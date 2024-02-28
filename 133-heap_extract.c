#include "binary_trees.h"
#include <stdlib.h>

/**
 * _tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0
 */

size_t _tree_height(const binary_tree_t *tree)
{
	size_t L, R;

	L = 0;
	R = 0;

	if (!tree)
		return (0);

	if (tree->left)
		L = 1 + _tree_height(tree->left);

	if (tree->right)
		R = 1 + _tree_height(tree->right);

	if (L >= R)
		return (L);
	else
		return (R);
}

/**
 * _tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size or 0
 */
size_t _tree_size(const binary_tree_t *tree)
{
	size_t L, R;

	if (!tree)
		return (0);

	L = _tree_size(tree->left);
	R = _tree_size(tree->right);
	return (L + R + 1);
}

/**
 * _tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: a pointer to the root
 * @node: the node
 * @H:height 
 * Return: Nothing
 */
void _tree_preorder(heap_t *tree, heap_t **node, size_t H)
{
	if (!tree || !node)
		return;

	if (!H)
		*node = tree;
	--H;
	_tree_preorder(tree->left, node, H);
	_tree_preorder(tree->right, node, H);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_tree_preorder(heap_r, &node, _tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
