#include "binary_trees.h"
/**
 * binary_tree_preorder - printint tree elements with pre-order traversal
 * @tree: to go through
 * @func: function that will use
 * Return: None
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
