#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: tree to delete
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
			binary_tree_delete(tree->l);
			binary_tree_delete(tree->r);
		}
		free(tree);
	}

}
