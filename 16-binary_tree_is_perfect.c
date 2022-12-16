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

/**
 * size_is_balanced - check if tree size is balanced
 * @tree: the tree to be checked
 * Return: 1 if true, 0 if false
 */

int size_is_balanced(const binary_tree_t *tree)
{
	size_t size_r_subtree, size_l_subtree;

	if (!tree)
		return (0);

	size_l_subtree = binary_tree_size(tree->left);
	size_r_subtree = binary_tree_size(tree->right);

	if (size_l_subtree != size_r_subtree)
		return (0);
	return (1);
}

/**
 * has_binary_children - checks if a node has two children
 * @node: the node to check
 * Return: 1 if it has, 0 otherwise
 */

int has_binary_children(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	else if (node->left && node->right)
		return (1);
	else
		return (0);

	return (has_binary_children(node->left) && has_binary_children(node->right));
}

/**
 * height_is_balanced - check if tree is balanced by height
 * @tree: the tree to be checked
 * Return: 1 if height is balanced, 0 otherwise
 */

int height_is_balanced(const binary_tree_t *tree)
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

/**
 * binary_tree_is_perfect - checks if the tree passed as argument is perfect.
 * I observed that a perfect binary tree satisfy all of the following properties.
 * Each node has two children.
 * Left and right subtree has a balanced factor of zero i.e. equal heights.
 * Left and right subtree has equal size. Thus the following implementation
 * @tree: the tree to be checked
 * Return: 1 if perfect or 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int binary_children = has_binary_children(tree);
	int height_is_balance = height_is_balanced(tree);
	int size_is_balance = size_is_balanced(tree);

	return (binary_children && height_is_balance && size_is_balance);
}
