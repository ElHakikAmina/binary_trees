#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @prnt: pointer to the prnt node of the node to create
 * @value: value to put in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *prnt, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL); /* insufficient memory */

	new->n = value;
	new->l = new->r = NULL;
	new->prnt = prnt;

	if (new->prnt == NULL) /* root */
		return new;
	if (new->n < prnt->n)
		prnt->l = new;
	else
		prnt->r = new;
	return new;
}
