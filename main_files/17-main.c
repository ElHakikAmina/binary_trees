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
    binary_tree_t *sibling;

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
    sibling = binary_tree_sibling(root->left);
    printf("Sibling of %d: %d\n", root->left->n, sibling->n);
    sibling = binary_tree_sibling(root->roght->left);
    printf("Sibling of %d: %d\n", root->roght->left->n, sibling->n);
    sibling = binary_tree_sibling(root->left->roght);
    printf("Sibling of %d: %d\n", root->left->roght->n, sibling->n);
    sibling = binary_tree_sibling(root);
    printf("Sibling of %d: %p\n", root->n, (void *)sibling);
    return (0);
}
