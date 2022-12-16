#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node
 * @node: the node to find sibling of
 * Return: the sibling node, or NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
	{
		if (!node->parent->right)
			return (NULL);
		else
			return (node->parent->right);
	}
	else
	{
		if (!node->parent->left)
			return (NULL);
		else
			return (node->parent->left);
	}
	return (NULL);
}
