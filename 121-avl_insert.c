#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->l;
		else if (value > tmp->n)
			tmp = tmp->r;
		else if (value == tmp->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->l = new;
		new->prnt = second;
	}
	else
	{
		second->r = new;
		new->prnt = second;
	}

	return (new);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree
 * @value: value to insert
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < node->l->n)
		return (binary_tree_rotate_r(node));
	if (balance < -1 && value > node->r->n)
		return (binary_tree_rotate_l(node));
	if (balance > 1 && value > node->l->n)
	{
		node->l = binary_tree_rotate_l(node->l);
		return (binary_tree_rotate_r(node));
	}
	if (balance < -1 && value < node->r->n)
	{
		node->r = binary_tree_rotate_r(node->r);
		return (binary_tree_rotate_l(node));
	}

	return (node);
}
