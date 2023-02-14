#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rr, *ll;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	rr = tree->right;
	ll = rr->left;

	rr->left = tree;
	tree->right = ll;

	tree->parent = rr;
	if (ll != NULL)
		ll->parent = tree;
	return (rr);
}
