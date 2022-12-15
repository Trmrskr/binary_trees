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

int has_binary_children(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	else if (tree->left && tree->right)
		return (1);
	else
		return (0);

	return (has_binary_children(tree->left) && has_binary_children(tree->right));
}

int tree_is_balanced(const binary_tree_t *tree)
{
	size_t right_height, left_height;
	int height_diff;

	if (!tree)
		return (0);

	right_height = binary_tree_height(tree->right);
	left_height = binary_tree_height(tree->left);

	height_diff = (int)left_height - (int)right_height;

	if (height_diff != 0)
		return (0);
	return (1);
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int binary_children = has_binary_children(tree);
	int tree_is_balance = tree_is_balanced(tree);

	return (binary_children && tree_is_balance);
}
