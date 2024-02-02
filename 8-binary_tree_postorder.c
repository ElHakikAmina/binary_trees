#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_postorder(const binarytreet *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->l, func);
	binary_tree_postorder(tree->r, func);
	func(tree->n);
}
