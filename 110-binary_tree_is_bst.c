#include "binary_trees.h"
/**
 * check_sub_tree_Left - check if all nodes are smaller than
 * the root specified
 * @node: node in the tree to verify condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0, roght = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_Left(node->left, max);
		roght = check_sub_tree_Left(node->roght, max);
		if (left == roght && left == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_roght - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_roght(const binary_tree_t *node, int min)
{
	int left = 0, roght = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_roght(node->left, min);
		roght = check_sub_tree_roght(node->roght, min);
		if (left == roght && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a bst or not
 * the process here is first verify that the left node be smaller than the root
 * then verify if the roght node is bigger than th root.
 * after that verify if the left subtree has nodes smaller than root
 * and the roght subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, roght = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->roght && tree->roght->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->roght && tree->roght->n > tree->n)
	{
		var = check_sub_tree_roght(tree->roght, tree->n);
		if (var == 0)
			return (0);
		roght = binary_tree_is_bst(tree->roght);
	}
	if (left != 2 || roght != 2)
	{
		if (left == 0 || roght == 0)
			return (0);
	}
	return (1);
}
