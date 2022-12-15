#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	
	return (binary_tree_size(tree->right) + binary_tree_size(tree->left) + 1);
}