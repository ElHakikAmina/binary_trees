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
    binarytreet *root;

    root = binary_tree_node(NULL, 98);
    root->l = binary_tree_node(root, 12);
    root->r = binary_tree_node(root, 402);
    binary_tree_insert_r(root->l, 54);
    binary_tree_insert_r(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
