#include "binary_trees.h"

/**
 * binary_tree_depth - finds depth of binary tree
 * @tree: tree whose depth is to be measured
 * Return: binary tree depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t D = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		D++;
		tree = tree->parent;
	}
	return (D);
}
