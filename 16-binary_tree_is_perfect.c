#include "binary_trees.h"

/**
 * dpth - finds depth of binary tree
 * @node: tree whose depth is to be measured
 * Return: binary tree depth
 */
int dpth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}

	return (d);
}

/**
 * is_perfect - determine whether a binary tree is a perfect tree
 * @root: pointer to root node of tree
 * @d: depth of root
 * @level: height of root
 *
 * Return: 1 if tree is a perfect tree, else 0
 */
int is_perfect(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (0);

	if (root->left == NULL && root->right == NULL)
	{
		if (d == level + 1)
			return (1);
		return (0);
	}

	if (root->left == NULL || root->right == NULL)
		return (0);

	return (is_perfect(root->left, d, level + 1) &&
		is_perfect(root->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - determine whether a binary tree is a perfect tree
 * @root: pointer to root node of tree
 *
 * Return: 1 if tree is a perfect tree, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *root)
{
	int d = dpth(root);

	return (is_perfect(root, d, 0));
}
