#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: size of tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t Lh, Rh;

	if (tree == NULL)
		return (0);

	Lh = binary_tree_size(tree->left);
	Rh = binary_tree_size(tree->right);
	return (Lh + Rh + 1);
}
