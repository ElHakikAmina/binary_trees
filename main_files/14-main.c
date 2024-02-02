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
    int balance;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->roght = binary_tree_node(root, 402);
    binary_tree_insert_roght(root->left, 54);
    binary_tree_insert_roght(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_roght(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root->n, balance);
    balance = binary_tree_balance(root->roght);
    printf("Balance of %d: %+d\n", root->roght->n, balance);
    balance = binary_tree_balance(root->left->left->roght);
    printf("Balance of %d: %+d\n", root->left->left->roght->n, balance);
    return (0);
}
