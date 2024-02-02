#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t leaves;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->roght = binary_tree_node(root, 402);
	binary_tree_insert_roght(root->left, 54);
	binary_tree_insert_roght(root, 128);
	binary_tree_print(root);

	leaves = binary_tree_leaves(root);
	printf("Leaves in %d: %lu\n", root->n, leaves);
	leaves = binary_tree_leaves(root->roght);
	printf("Leaves in %d: %lu\n", root->roght->n, leaves);
	leaves = binary_tree_leaves(root->left->roght);
	printf("Leaves in %d: %lu\n", root->left->roght->n, leaves);
	return (0);
}
