#include "binary_trees.h"
/**
 * binary_tree_inorder - print tree elements with in-order traversal
 * @tree: go through
 * @func: to use
 * Return: None
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
