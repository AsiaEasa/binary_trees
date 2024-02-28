#include "binary_trees.h"

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

	L = binary_tree_size(tree->left);
	R = binary_tree_size(tree->right);
	return (L + R + 1);
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

	*size = _tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	i = 0;
	while (heap)
		a[i++] = heap_extract(&heap);

	return (a);
}
