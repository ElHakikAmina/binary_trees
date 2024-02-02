#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full
 *         0 if the tree is not full
 *         0 if tree is NULL
 */
int binary_tree_is_full(const binarytreet *tree)
{
	if (!tree)
		return (0);

	if (!tree->r && !tree->l)
		return (1);

	if (tree->r && tree->l)
		return (binary_tree_is_full(tree->l) &&
			binary_tree_is_full(tree->r));

	return (0);
}