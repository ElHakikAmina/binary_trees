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
    int complete;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->roght = binary_tree_node(root, 128);
    root->left->roght = binary_tree_node(root->left, 54);
    root->roght->roght = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 10);
    root->roght->left = binary_tree_node(root->roght, 45);

    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);
    complete = binary_tree_is_complete(root->left);
    printf("Is %d complete: %d\n", root->left->n, complete);

    root->roght->left = binary_tree_node(root->roght, 112);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    root->left->left->left = binary_tree_node(root->left->left, 8);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    root->left->roght->left = binary_tree_node(root->left->roght, 23);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    binary_tree_delete(root);
    return (0);
}
