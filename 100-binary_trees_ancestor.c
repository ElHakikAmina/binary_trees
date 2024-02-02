#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binarytreet *binary_trees_ancestor(const binarytreet *first,
				     const binarytreet *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->prnt;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->prnt;
		depth_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binarytreet *)first);
		first = first->prnt;
		second = second->prnt;
	}
	return ((binarytreet *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binarytreet *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->prnt)
	{
		depth++;
		tree = tree->prnt;
	}

	return (depth);
}
