#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

/**
 * struct binarytree - Binary tree node
 *
 * @n: Integer stored in the node
 * @prnt: Pointer to the prnt node
 * @l: Pointer to the l child node
 * @r: Pointer to the r child node
 */
struct binarytree
{
	int n;
	struct binarytree *prnt;
	struct binarytree *l;
	struct binarytree *r;
};

typedef struct binarytree binary_tree_t;
typedef struct binarytree bst_t;
typedef struct binarytree avl_t;
typedef struct binarytree heap_t;

/* binary_tree_print.c */
void binary_tree_print(const binary_tree_t *);

/* tasks */
binary_tree_t *binary_tree_node(binary_tree_t *prnt, int value);
binary_tree_t *binary_tree_insert_l(binary_tree_t *prnt, int value);
binary_tree_t *binary_tree_insert_r(binary_tree_t *prnt, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binarytreeize(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binarytreeibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Advanced tasks */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_l(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_r(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/* helper functions */
int _pow_recursion(int x, int y);
binary_tree_t *bta_helper(binary_tree_t *root, const binary_tree_t *first,
			  const binary_tree_t *second);
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
int btib_helper(const binary_tree_t *tree, int low, int hi);
bst_t *bst_min_val(bst_t *root);
int btia_helper(const binary_tree_t *tree, int low, int hi);
int btih_helper(const binary_tree_t *tree);
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi);

#endif
