#include "binary_trees.h"
/**
 * array_to_heap - change an array to a HEAP tree
 * @array: array
 * @size: size of array
 * Return: HEAP tree from array
 */
heap_t *array_to_heap(int *array, size_t size)
{
        int i;
        heap_t *root;

        root = NULL;
        if (size == 0)
                return (NULL);

        i = 0;
        while (i < (int)size)
        {
                if (i == 0)
                {
                        if (!heap_insert(&root, array[i]))
                                return (NULL);
                }
                else
                {
                        if (!heap_insert(&root, array[i]))
                                return (NULL);
                }
                i++;
        }
        return (root);
}
