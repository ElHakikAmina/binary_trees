#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to check
 *
 * Return: 1 if node is a leaf
 *         0 if not a leaf
 *         0 if node is NULL
 */
int binary_tree_is_leaf(const binarytreet *node)
{
	return ((!node || node->l || node->r) ? 0 : 1);
}