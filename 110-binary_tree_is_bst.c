#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - checks if a binary tree is a binary seach tree
 * @tree: pointer to root node to of tree to check
 * @min: smallest allowable integer value
 * @max: largest allowable integer value
 *
 * Return: 1 if bst, 0 if not or if tree is NULL
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min,
		       tree->n - 1) && is_bst(tree->right, tree->n + 1, max));

}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if treeis valid BST, 0 if not or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
