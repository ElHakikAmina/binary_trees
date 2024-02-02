#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_inorder(const binarytreet *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->l, func);
	func(tree->n);
	binary_tree_inorder(tree->r, func);
}