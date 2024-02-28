#include "binary_trees.h"


/**
 * binary_tree_levelorder - goes through a binary
 * @tree: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree, 
 */
int binary_tree_levelorder(int *tree, size_t size)
{
	size_t H, L;

	H = binary_tree_height(tree);

	L = 0;
	while (L <= H)
	{
		L++;
	}
}
/**
 * sorted_array_to_avl - builds an AVL tree
 * @array: pointer to the first element
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree,
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);

	return (binary_tree_levelorder(array,size));
}
