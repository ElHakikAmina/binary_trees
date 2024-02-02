#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
 *         0 if tree is NULL
 */
int binary_tree_balance(const binarytreet *tree)
{
	int height_l, height_r;

	if (!tree)
		return (0);

	height_l = tree->l ? (int)binary_tree_height(tree->l) : -1;
	height_r = tree->r ? (int)binary_tree_height(tree->r) : -1;

	return (height_l - height_r);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binarytreet *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->l ? 1 + binary_tree_height(tree->l) : 0;
	height_r = tree->r ? 1 + binary_tree_height(tree->r) : 0;
	return (height_l > height_r ? height_l : height_r);
}
