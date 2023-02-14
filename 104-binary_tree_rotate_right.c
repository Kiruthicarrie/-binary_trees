#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rr, *ll;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	ll = tree->left;
	rr = ll->right;

	ll->right = tree;
	tree->left = rr;

	tree->parent = ll;
	if (rr != NULL)
		rr->parent = tree;
	return (ll);
}
