#include "binary_trees.h"
/**
 * binary_tree_depth - depth specified node  root
 * @tree: checking the depth
 * Return: 0 is root if no is number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
