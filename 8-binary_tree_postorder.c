#include "binary_trees.h"

/**
 * binarytreepositiontorder - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binarytreepositiontorder(const binarytreet *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binarytreepositiontorder(tree->l, func);
	binarytreepositiontorder(tree->r, func);
	func(tree->n);
}
