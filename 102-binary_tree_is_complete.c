#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binarytreet *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binarytreeize(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_helper(const binarytreet *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->l, 2 * index + 1, size) &&
		btic_helper(tree->r, 2 * index + 2, size));
}

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

	return (binarytreeize(tree->l) +
		binarytreeize(tree->r) + 1);
}