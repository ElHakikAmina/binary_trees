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

typedef struct binarytree binarytreet;
typedef struct binarytree bstt;
typedef struct binarytree avlt;
typedef struct binarytree heapt;

/* binary_tree_print.c */
void binary_tree_print(const binarytreet *);

/* tasks */
binarytreet *binary_tree_node(binarytreet *prnt, int value);
binarytreet *binary_tree_insert_l(binarytreet *prnt, int value);
binarytreet *binary_tree_insert_r(binarytreet *prnt, int value);
void binary_tree_delete(binarytreet *tree);
int binary_tree_is_leaf(const binarytreet *node);
int binary_tree_is_root(const binarytreet *node);
void binary_tree_preorder(const binarytreet *tree, void (*func)(int));
void binary_tree_inorder(const binarytreet *tree, void (*func)(int));
void binary_tree_postorder(const binarytreet *tree, void (*func)(int));
size_t binary_tree_height(const binarytreet *tree);
size_t binary_tree_depth(const binarytreet *tree);
size_t binarytreeize(const binarytreet *tree);
size_t binary_tree_leaves(const binarytreet *tree);
size_t binary_tree_nodes(const binarytreet *tree);
int binary_tree_balance(const binarytreet *tree);
int binary_tree_is_full(const binarytreet *tree);
int binary_tree_is_perfect(const binarytreet *tree);
binarytreet *binarytreeibling(binarytreet *node);
binarytreet *binary_tree_uncle(binarytreet *node);

/* Advanced tasks */
binarytreet *binary_trees_ancestor(const binarytreet *first,
				     const binarytreet *second);
void binary_tree_levelorder(const binarytreet *tree, void (*func)(int));
int binary_tree_is_complete(const binarytreet *tree);
binarytreet *binary_tree_rotate_l(binarytreet *tree);
binarytreet *binary_tree_rotate_r(binarytreet *tree);
int binary_tree_is_bst(const binarytreet *tree);
bstt *bst_insert(bstt **tree, int value);
bstt *array_to_bst(int *array, size_t size);
bstt *bst_search(const bstt *tree, int value);
bstt *bst_remove(bstt *root, int value);
int binary_tree_is_avl(const binarytreet *tree);
avlt *avl_insert(avlt **tree, int value);
avlt *array_to_avl(int *array, size_t size);
avlt *avl_remove(avlt *root, int value);
avlt *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binarytreet *tree);
heapt *heap_insert(heapt **root, int value);
heapt *array_to_heap(int *array, size_t size);
int heap_extract(heapt **root);
int *heapto_sorted_array(heapt *heap, size_t *size);

/* helper functions */
int _pow_recursion(int x, int y);
binarytreet *bta_helper(binarytreet *root, const binarytreet *first,
			  const binarytreet *second);
void btlo_helper(const binarytreet *tree, void (*func)(int), size_t level);
int btic_helper(const binarytreet *tree, size_t index, size_t size);
int btib_helper(const binarytreet *tree, int low, int hi);
bstt *bst_min_val(bstt *root);
int btia_helper(const binarytreet *tree, int low, int hi);
int btih_helper(const binarytreet *tree);
void sata_helper(avlt **root, int *array, size_t lo, size_t hi);

#endif
