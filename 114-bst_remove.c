#include <stdlib.h>
#include "binary_trees.h"

/**
 * min_node - returns the min node in a tree
 * @node: pointer to the node whose min node is required
 *
 * Return: min node or NULL
 */
bst_t *min_node(bst_t *node)
{
	bst_t *temp = node;

	while (temp != NULL && temp->left != NULL)
		temp = temp->left;

	return (temp);
}

/**
 * bst_search - insert a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to search the value in
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the node or NULL on failure
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *curr = (bst_t *)tree;

	while (curr != NULL)
	{
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else if (value == curr->n)
			break;
	}
	return (curr);
}

/**
 * bst_delete - Deletes a node from a BST
 * @root: root node pointer
 * @node: node to delete from BST
 *
 * Return: pointer to new root node
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *succ = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	/* Left child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	succ = min_node(node->right);
	node->n = succ->n;

	return (bst_delete(root, succ));
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *curr = NULL;

	if (root == NULL)
		return (root);

	curr = bst_search(root, value);
	if (curr == NULL)
		return (root);

	return (bst_delete(root, curr));
}
