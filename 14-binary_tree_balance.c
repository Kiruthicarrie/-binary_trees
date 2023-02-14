#include "binary_trees.h"

/**
 * max_node - return the max value between 2 integers
 * @a: first integer
 * @b: second integer
 *
 * Return: larger value
 */
int max_node(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * tree_height - measure the height of a binary tree
 * @tree: tree to be measured
 *
 * Return: height of the tree
 */

int tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max_node(tree_height(tree->left),
			tree_height(tree->right)));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}
