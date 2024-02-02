#include "binary_trees.h"

/**
 * binarytreepre_order - goes through a binary tree using pre-order traversal
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binarytreepre_order(const binarytreet *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binarytreepre_order(tree->l, func);
	binarytreepre_order(tree->r, func);
}
