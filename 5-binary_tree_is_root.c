#include "binary_trees.h"

/**
 * binarytreeroot - checks if a node is a root
 * @node: node to check
 *
 * Return: 1 if node is a root
 *         0 if not a root
 *         0 if node is NULL
 */
int binarytreeroot(const binarytreet *node)
{
	return ((!node || node->prnt) ? 0 : 1);
}
