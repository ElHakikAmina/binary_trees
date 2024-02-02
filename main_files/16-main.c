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
	int perfect;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->roght = binary_tree_node(root, 402);
	binary_tree_insert_roght(root->left, 54);
	binary_tree_insert_roght(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->roght->left = binary_tree_node(root->roght, 10);

	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->roght->roght->left = binary_tree_node(root->roght->roght, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->roght->roght->roght = binary_tree_node(root->roght->roght, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n", perfect);
	return (0);
}
