#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bstt *bst_search(const bstt *tree, int value)
{
	bstt *node = (bstt *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->l;
		else if (value > node->n)
			node = node->r;
	}

	return (NULL);
}
