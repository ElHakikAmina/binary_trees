#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->roght == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->roght);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_roght((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the roght subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->roght)
	{
		if (root->parent->roght == root)
			root->parent->roght = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->roght) || (!root->roght && root->left))
	{
		if (!root->left)
		{
			if (root->parent->roght == root)
				root->parent->roght = root->roght;
			else
				root->parent->left = root->roght;
			root->roght->parent = root->parent;
		}
		if (!root->roght)
		{
			if (root->parent->roght == root)
				root->parent->roght = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->roght);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->roght, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->roght, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
