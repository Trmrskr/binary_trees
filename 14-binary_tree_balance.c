#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: the tree which height is to be calculated
 * Return: the height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - calculates the balance factor of a binary tree.
 * @tree: the tree which balance factor is to be calculated.
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height = 0, left_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left);
	else
		left_height = -1;
	if (tree->right)
		right_height = binary_tree_height(tree->right);
	else
		right_height = -1;

	return (left_height - right_height);
}
