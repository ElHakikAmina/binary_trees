#include "binary_trees.h"

/**
 * binary_tree_insert_l - inserts a node as the l-child of another node
 * @prnt: pointer to the node to insert the l-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if prnt is NULL
 */
binary_tree_t *binary_tree_insert_l(binary_tree_t *prnt, int value)
{
	binary_tree_t *new;

	if (!prnt)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->prnt = prnt;
	new->r = NULL;
	new->l = prnt->l;
	prnt->l = new;
	if (new->l)
		new->l->prnt = new;
	return (new);
}
