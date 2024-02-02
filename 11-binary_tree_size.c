#include "binary_trees.h"

/**
 * binarytreeize - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binarytreeize(const binarytreet *tree)
{
	if (!tree)
		return (0);

	return (binarytreeize(tree->l) + binarytreeize(tree->r) + 1);
}
