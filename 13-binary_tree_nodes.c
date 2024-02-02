#include "binary_trees.h"

/**
 * binarytreendes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree to count the nodes from
 *
 * Return: number of nodes counted
 *         0 if tree is NULL
 */
size_t binarytreendes(const binarytreet *tree)
{
	if (!tree || (!tree->l && !tree->r))
		return (0);

	return (binarytreeize(tree) - binary_tree_leaves(tree));
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

	return (binarytreeize(tree->l) + binarytreeize(tree->r) + 1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree to count the leaves from
 *
 * Return: number of leaves
 *         0 if tree is NULL
 */
size_t binary_tree_leaves(const binarytreet *tree)
{
	if (!tree)
		return (0);

	if (!tree->l && !tree->r)
		return (1);

	return (binary_tree_leaves(tree->l) + binary_tree_leaves(tree->r));
}
