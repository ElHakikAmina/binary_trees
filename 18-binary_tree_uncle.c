#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node
 *         NULL if node is NULL
 *         NULL if the prnt is NULL
 *         NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->prnt)
		return (NULL);

	return (binarytreeibling(node->prnt));
}

/**
 * binarytreeibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node
 *         NULL if node is NULL
 *         NULL if the prnt is NULL
 *         NULL if the node has no siblings
 */
binary_tree_t *binarytreeibling(binary_tree_t *node)
{
	if (!node || !node->prnt)
		return (NULL);

	if (node == node->prnt->l)
		return (node->prnt->r);
	return (node->prnt->l);
}
