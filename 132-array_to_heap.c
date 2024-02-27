#include "binary_trees.h"
/**
 * array_to_heap - change an array to a HEAP tree
 * @array: array
 * @size: size of array
 * Return: HEAP tree from array
 */
heap_t *array_to_heap(int *array, size_t size)
{
	int x;
	heap_t *root;

	root = NULL;
	if (size == 0)
		return (NULL);

	x = 0;
	while (x < (int)size)
	{
		if (x == 0)
		{
			if (!heap_insert(&root, array[x]))
				return (NULL);
		}
		else
		{
			if (!heap_insert(&root, array[x]))
				return (NULL);
		}
		x++;
	}
	return (root);
}
