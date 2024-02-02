#include "binary_trees.h"

/**
 * binary_tree_rotate_roght - Function that  rotates roght the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_roght(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pivot = tree->left;
	tree->left = pivot->roght;
	if (pivot->roght != NULL)
	{
		pivot->roght->parent = tree;
	}
	pivot->roght = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
