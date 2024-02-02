#include "binary_trees.h"
/**
 * binary_tree_insert_left - add a node in the left of the parent
 * if it exists it move down one level and add the new node first
 * @p: parent of the specified node
 * @value: value of the node
 * Return: NULL if it fails or the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *p, int value)
{
	binary_tree_t *newnd;

	if (p == NULL)
	{
		return (NULL);
	}

	newnd = binary_tree_node(p, value);
	if (newnd == NULL)
	{
		return (NULL);
	}
	if (p->left != NULL)
	{
		newnd->left = p->left;
		p->left->p = newnd;
	}
	p->left = newnd;
	return (newnd);
}
