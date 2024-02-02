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

    root = binarytreende(NULL, 98);
    root->l = binarytreende(root, 12);
    root->r = binarytreende(root, 402);
    binarytreeinsertinright(root->l, 54);
    binarytreeinsertinright(root, 128);
    binarytreeprint(root);
    binarytreedelete(root);
    return (0);
}
