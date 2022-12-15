#include "binary_trees.h"

/**
 * binary_tree_inorder - a method that traverses a binary tree using
 * inorder traversal
 * @tree: the tree to be traversed.
 * @func: a function to manipulate each node of the tree.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
