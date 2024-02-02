#include "binary_trees.h"

/**
 * binary_tree_rotate_r - performs a r-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binarytreet *binary_tree_rotate_r(binarytreet *tree)
{
	binarytreet *tmp = NULL, *prnt;

	if (!tree || !tree->l)
		return (NULL);
	tmp = tree;
	prnt = tree->prnt;
	tree = tree->l;
	tree->prnt = NULL;
	if (tree->r)
	{
		tmp->l = tree->r;
		tree->r->prnt = tmp;
	}
	else
		tmp->l = NULL;
	tmp->prnt = tree;
	tree->r = tmp;
	if (prnt)
		prnt->l = tree;
	tree->prnt = prnt;
	return (tree);
}
