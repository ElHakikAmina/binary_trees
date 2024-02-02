#include "binary_trees.h"

/**
 * binary_tree_insert_r - inserts a node as the r-child of another node
 * @prnt: pointer to the node to insert the r-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if prnt is NULL
 */
binarytreet *binary_tree_insert_r(binarytreet *prnt, int value)
{
	binarytreet *new;

	if (!prnt)
		return (NULL);

	new = malloc(sizeof(binarytreet));
	if (!new)
		return (NULL);

	new->n = value;
	new->prnt = prnt;
	new->l = NULL;
	new->r = prnt->r;
	prnt->r = new;
	if (new->r)
		new->r->prnt = new;
	return (new);
}
