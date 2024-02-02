#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to create from
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avlt *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avlt *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
