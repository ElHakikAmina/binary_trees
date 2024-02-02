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
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->roght = binary_tree_node(root, 128);
    root->left->roght = binary_tree_node(root->left, 54);
    root->roght->roght = binary_tree_node(root->roght, 402);
    root->left->left = binary_tree_node(root->left, 10);
    root->roght->left = binary_tree_node(root->roght, 110);
    root->roght->roght->left = binary_tree_node(root->roght->roght, 200);
    root->roght->roght->roght = binary_tree_node(root->roght->roght, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root->roght->left);
    printf("Uncle of %d: %d\n", root->roght->left->n, uncle->n);
    uncle = binary_tree_uncle(root->left->roght);
    printf("Uncle of %d: %d\n", root->left->roght->n, uncle->n);
    uncle = binary_tree_uncle(root->left);
    printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);
    return (0);
}
