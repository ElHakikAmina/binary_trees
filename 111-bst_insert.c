#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bstt *bst_insert(bstt **tree, int value)
{
	bstt *tmp = NULL;
	bstt *second = NULL;
	bstt *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->l;
		else if (value > tmp->n)
			tmp = tmp->r;
		else if (value == tmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->l = new;
		new->prnt = second;
	}
	else
	{
		second->r = new;
		new->prnt = second;
	}

	return (new);
}
