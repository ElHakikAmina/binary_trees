#include "binary_trees.h"

/**
 * binary_tree_is_root - this function checks if the node is root
 * @node: Node that will be checked
 * Return: 0 not root 1 is a root
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
