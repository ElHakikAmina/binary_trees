#include "binary_trees.h"
/**
 * successor - get the next successor i mean the min node in the r subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bstt *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = successor(node->l);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}

}
/**
 * two_children - function that gets the next successor using the min
 * value in the r subtree, and then replace the node value for
 * this successor
 * @root: node tat has two children
 * Return: the value found
 */
int two_children(bstt *root)
{
	int new_value = 0;

	new_value = successor(root->r);
	root->n = new_value;
	return (new_value);
}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bstt *root)
{
	if (!root->l && !root->r)
	{
		if (root->prnt->r == root)
			root->prnt->r = NULL;
		else
			root->prnt->l = NULL;
		free(root);
		return (0);
	}
	else if ((!root->l && root->r) || (!root->r && root->l))
	{
		if (!root->l)
		{
			if (root->prnt->r == root)
				root->prnt->r = root->r;
			else
				root->prnt->l = root->r;
			root->r->prnt = root->prnt;
		}
		if (!root->r)
		{
			if (root->prnt->r == root)
				root->prnt->r = root->l;
			else
				root->prnt->l = root->l;
			root->l->prnt = root->prnt;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bstt *bst_remove(bstt *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->l, value);
	else if (value > root->n)
		bst_remove(root->r, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->r, type);
	}
	else
		return (NULL);
	return (root);
}