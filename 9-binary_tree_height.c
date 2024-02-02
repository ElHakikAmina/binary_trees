#include "binary_trees.h"

/**
 * binarytreeheight - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binarytreeheight(const binarytreet *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->l ? 1 + binarytreeheight(tree->l) : 0;
	height_r = tree->r ? 1 + binarytreeheight(tree->r) : 0;
	return (height_l > height_r ? height_l : height_r);
}
