#include "binary_trees.h"

/**
 * binarytreedelete - deletes an entire binary tree
 * @tree: tree to delete
 */
void binarytreedelete(binarytreet *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binarytreedelete(tree->l);
			binarytreedelete(tree->r);
		}
		free(tree);
	}

}
