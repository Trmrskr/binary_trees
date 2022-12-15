#include "binary_trees.h"

/**
 * binary_tree_preorder - a method that traverses a binary tree using preorder traversal
 * @tree: the tree to be traversed.
 * @func: a function to manipulate each node of the tree.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
