#include "binary_trees.h"
/**
 * binary_tree_insert_right - add a node in the right of the parent
 * if it exists it move down one level and add the new node first
 * @parent: specified node parent
 * @value: node value
 * Return: NULL or new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnd;

	if (parent == NULL)
	{
		return (NULL);
	}

	newnd = binary_tree_node(parent, value);
	if (newnd == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		newnd->right = parent->right;
		parent->right->parent = newnd;
	}
	parent->right = newnd;
	return (newnd);
}
