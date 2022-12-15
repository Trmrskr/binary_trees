#include "binary_trees.h"

/**
 * binary_tree_delete - deletes the node of a binary tree
 * @tree: tree which nodes are to be deleted
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
