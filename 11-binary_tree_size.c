#include "binary_trees.h"

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: the tree whose size is to be calculated
 * Return: the size of the given tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->right) + binary_tree_size(tree->left) + 1);
}
