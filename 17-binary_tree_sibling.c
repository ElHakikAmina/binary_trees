#include "binary_trees.h"

/**
 * binary_tree_sibling - func finds if a node is sibling
 * @node: node that will check
 * Return: Sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
