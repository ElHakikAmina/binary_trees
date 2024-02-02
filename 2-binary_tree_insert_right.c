#include "binary_trees.h"
/**
 * binary_tree_insert_roght - add a node in the roght of the parent
 * if it exists it move down one level and add the new node first
 * @parent: parent of the specified node
 * @value: value of the node
 * Return: NULL if it fails or the new node
 */

binary_tree_t *binary_tree_insert_roght(binary_tree_t *parent, int value)
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
	if (parent->roght != NULL)
	{
		newnd->roght = parent->roght;
		parent->roght->parent = newnd;
	}
	parent->roght = newnd;
	return (newnd);
}
