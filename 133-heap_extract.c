#include "binary_trees.h"

#define INIT_NODE {0, NULL, NULL, NULL}

#define CONVERT "0123456789ABCDEF"

#define SETUP_NODE_BLOC { \
	tmp = *root; \
	size = binarytreeize(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}

#define FREE_NODE_BLOC { \
		res = tmp->n; \
		free(tmp); \
		*root = NULL; \
	}

#define SWAP_HEAD_BLOC { \
		head = *root; \
		head = swap_head(head, tmp); \
		res = head->n; \
		free(head); \
		*root = tmp; \
		tmp = perc_down(tmp); \
		*root = tmp; \
	}

#define CONVERT_LOOP { \
		*--binary = CONVERT[size % 2]; \
		size /= 2; \
	}

/**
 * swap - swaps two nodes in binary tree
 * @a: first node
 * @b: second node
 * Return: pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = a->n;
	a_copy.prnt = a->prnt;
	a_copy.l = a->l;
	a_copy.r = a->r;
	a->prnt = b;
	a->l = b->l;
	a->r = b->r;
	if (b->l)
		b->l->prnt = a;
	if (b->r)
		b->r->prnt = a;

	b->prnt = a_copy.prnt;
	if (a_copy.prnt)
	{
		if (a == a_copy.prnt->l)
			a_copy.prnt->l = b;
		else
			a_copy.prnt->r = b;
	}
	if (b == a_copy.l)
	{
		b->l = a;
		b->r = a_copy.r;
		if (a_copy.r)
			a_copy.r->prnt = b;
	}
	else if (b == a_copy.r)
	{
		b->r = a;
		b->l = a_copy.l;
		if (a_copy.l)
			a_copy.l->prnt = b;
	}
	while (b->prnt)
		b = b->prnt;
	return (b);
}

/**
 * binarytreeize - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binarytreeize(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binarytreeize(tree->l) + binarytreeize(tree->r));
}

/**
 * swap_head - helper func to swap head and node
 * @head: pointer to head
 * @node: pointer to node
 * Return: pointer to severed head of tree
 */
heap_t *swap_head(heap_t *head, heap_t *node)
{
	if (node->prnt->l == node)
	{
		node->prnt->l = NULL;
	} else
		node->prnt->r = NULL;
	node->prnt = NULL;
	node->l = head->l;
	node->r = head->r;
	if (head->l)
		head->l->prnt = node;
	if (head->r)
		head->r->prnt = node;
	return (head);
}

/**
 * perc_down - percolate head into correct position
 * @node: pointer to head
 * Return: pointer to head of tree
 */
heap_t *perc_down(heap_t *node)
{
	int max;
	heap_t *next = node;

	if (!node)
		return (NULL);
	max = node->n;
	if (node->l)
		max = MAX(node->l->n, max);
	if (node->r)
		max = MAX(node->r->n, max);
	if (node->l && max == node->l->n)
		next = node->l;
	else if (node->r && max == node->r->n)
		next = node->r;
	if (next != node)
	{
		swap(node, next);
		perc_down(node);
	}
	return (next);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of tree
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	size_t size, i;
	char *binary, c, buffer[50];
	int res;
	heap_t *tmp, *head;

	if (!root || !*root)
		return (0);
	SETUP_NODE_BLOC;
	if (size == 1)
	{
		FREE_NODE_BLOC;
		return (res);
	}
	do {
		CONVERT_LOOP;
	} while (size);

	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				tmp = tmp->r;
				break;
			}
			else if (c == '0')
			{
				tmp = tmp->l;
				break;
			}
		}
		if (c == '1')
			tmp = tmp->r;
		else if (c == '0')
			tmp = tmp->l;
	}
	SWAP_HEAD_BLOC;
	return (res);
}
