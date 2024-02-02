#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor->n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->roght = binary_tree_node(root, 402);
    root->left->roght = binary_tree_node(root->left, 54);
    root->roght->roght = binary_tree_node(root->roght, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->roght->left = binary_tree_node(root->roght, 45);
    root->roght->roght->left = binary_tree_node(root->roght->roght, 92);
    root->roght->roght->roght = binary_tree_node(root->roght->roght, 65);
    binary_tree_print(root);

    launch_test(root->left, root->roght);
    launch_test(root->roght->left, root->roght->roght->roght);
    launch_test(root->roght->roght, root->roght->roght->roght);
    return (0);
}
