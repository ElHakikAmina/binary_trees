#include "binary_trees.h"

/**
 * binarytreeinsertinleft - inserts a node as the l-child of another node
 * @prnt: pointer to the node to insert the l-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if prnt is NULL
 */
binarytreet *binarytreeinsertinleft(binarytreet *prnt, int value)
{
	binarytreet *new;

	if (!prnt)
		return (NULL);

	new = malloc(sizeof(binarytreet));
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
