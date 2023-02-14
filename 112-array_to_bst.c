#include "binary_trees.h"

/**
 * array_to_bst - build a BST from an array
 * @array: pointer to the first element of array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created BST or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t idx = 1;

	if (array == NULL)
		return (NULL);
	/* add first element which will be root element */
	root = bst_insert(&root, array[0]);
	while (idx < size)
	{
		bst_insert(&root, array[idx]);
		idx++;
	}
	return (root);
}
