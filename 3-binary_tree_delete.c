#include "binary_trees.h"
/**
 * binary_tree_delete - free a tree with recursion free the node
 * if node left and right is NULL
 * @tree: free tree
 * Return: none
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
