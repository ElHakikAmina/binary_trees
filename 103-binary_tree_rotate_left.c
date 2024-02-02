#include "binary_trees.h"

/**
 * binary_tree_rotate_l - performs a l-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_l(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *prnt;

	if (!tree || !tree->r)
		return (NULL);
	tmp = tree;
	prnt = tree->prnt;
	tree = tree->r;
	tree->prnt = NULL;
	if (tree->l)
	{
		tmp->r = tree->l;
		tree->l->prnt = tmp;
	}
	else
		tmp->r = NULL;
	tmp->prnt = tree;
	tree->l = tmp;
	if (prnt)
		prnt->r = tree;
	tree->prnt = prnt;
	return (tree);
}
