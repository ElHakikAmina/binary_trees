#include "binary_trees.h"
/**
 * binary_tree_insert_left - adding the node to the left of the parent
 * if it exists it move down one level and add the new node first
 * @parent: specified node parent
 * @value: node value
 * Return: NULL  or new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left != NULL)
	{
		newnd->left = parent->left;
		parent->left->parent = newnd;
	}
	parent->left = newnd;
	return (newnd);
}
