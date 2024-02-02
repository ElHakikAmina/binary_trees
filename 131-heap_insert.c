#include "binary_trees.h"
#include<stdlib.h>
#include<string.h>
#define INIT_NODE {0, NULL, NULL, NULL}

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
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = 0;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
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
 * insert - helper func to insert node to correct location
 * @root: double pointer to root of max heap
 * @node: node to insert
 */
void insert(heap_t **root, heap_t *node)
{
	heap_t *tmp;
	int size;
	unsigned int i;
	char *binary;
	char c;

	tmp = *root;
	size = binarytreeize(tmp) + 1;
	binary = convert(size, 2, 1);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				node->prnt = tmp;
				tmp->r = node;
				break;
			}
			else if (c == '0')
			{
				node->prnt = tmp;
				tmp->l = node;
				break;
			}
		}
		if (c == '1')
			tmp = tmp->r;
		else if (c == '0')
			tmp = tmp->l;
	}
}


/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *ht = NULL, *ret;

	if (!root)
		return (NULL);
	ht = calloc(1, sizeof(heap_t));
	ht->n = value;
	if (!*root)
	{
		*root = ht;
		return (ht);
	}
	insert(root, ht);
	while (ht->prnt && ht->n > ht->prnt->n)
	{
		ret = swap(ht->prnt, ht);
		if (ret)
			*root = ret;
	}
	return (ht);
}
