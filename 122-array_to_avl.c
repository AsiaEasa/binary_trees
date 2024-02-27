#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	int i;
	avl_t *root;

	root = NULL;
	if (size == 0)
		return (NULL);

	i = 0;
	while (i < (int)size)
	{
		if (i == 0)
		{
			if (!(avl_insert(&root, array[i])))
			return (NULL);
		}
		else
		{
			if (!avl_insert(&root, array[i]))
			return (NULL);
		}
		i++;
	}
	return (root);
}
