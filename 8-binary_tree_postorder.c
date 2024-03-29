#include "binary_trees.h"
/**
 * binary_tree_postorder - print tree elements with post-order traversal
 * @tree: go through
 * @func: to use
 * Return: None
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
