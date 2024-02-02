#include "binary_trees.h"

/**
 * binarytreein_order - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binarytreein_order(const binarytreet *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binarytreein_order(tree->l, func);
	func(tree->n);
	binarytreein_order(tree->r, func);
}
