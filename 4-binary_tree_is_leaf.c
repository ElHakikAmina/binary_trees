#include "binary_trees.h"
/**
 * binary_tree_is_leaf - if a node is leaf, it means the node
 * doesnt have a child in left or right
 * @node: node for the study
 * Return: 1 if is a leaf and 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
