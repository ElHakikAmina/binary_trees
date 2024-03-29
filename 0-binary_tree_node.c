#include "binary_trees.h"

/**
 * binary_tree_node - function that Create a binary node
 * @parent: node parent
 * @value: Value of node
 * Return: new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnd;

	newnd = malloc(sizeof(binary_tree_t));
	if (newnd == NULL)
		return (NULL);
	newnd->n = value;
	newnd->parent = parent;
	newnd->left = NULL;
	newnd->right = NULL;
	return (newnd);
}
