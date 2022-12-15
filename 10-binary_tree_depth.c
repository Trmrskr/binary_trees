#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a binary tree
 * @tree: the tree which height is to be calculated
 * Return: the depth of the tree.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
