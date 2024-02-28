#include "binary_trees.h"

/**
 * tr_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size or 0
 */
size_t tr_size(const binary_tree_t *tree)
{
	size_t L, R;

	if (!tree)
		return (0);

	if (tree->left)
		L = 1 + tree_size(tree->left);

	if (tree->right)
		R = 1 + tree_size(tree->right);

	return (L + R);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tr_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	i = 0;
	while (heap)
		a[i++] = heap_extract(&heap);

	return (a);
}
