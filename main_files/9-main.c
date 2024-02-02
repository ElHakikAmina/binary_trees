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
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->roght = binary_tree_node(root, 402);
    binary_tree_insert_roght(root->left, 54);
    binary_tree_insert_roght(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->roght);
    printf("Height from %d: %lu\n", root->roght->n, height);
    height = binary_tree_height(root->left->roght);
    printf("Height from %d: %lu\n", root->left->roght->n, height);
    return (0);
}
