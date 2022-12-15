#include "binary_trees.h"

/**
 * binary_tree_postorder - a method that traverses a binary tree using
 * postorder traversal
 * @tree: the tree to be traversed.
 * @func: a function to manipulate each node of the tree.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
