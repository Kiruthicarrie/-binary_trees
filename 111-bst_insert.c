#include "binary_trees.h"

/**
 * bst_insert - insert a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value in
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr = NULL;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = binary_tree_node(NULL, value);
			return (*tree);
		}
		curr = *tree;
		while (curr != NULL)
		{
			if (value < curr->n)
			{
				if (curr->left == NULL)
				{
					curr->left = binary_tree_node(curr, value);
					return (curr->left);
				}
				curr = curr->left;
			}
			if (value > curr->n)
			{
				if (curr->right == NULL)
				{
					curr->right = binary_tree_node(curr, value);
					return (curr->right);
				}
				curr = curr->right;
			}
			if (value == curr->n)
				return (NULL);
		}
	}
	return (NULL);
}
