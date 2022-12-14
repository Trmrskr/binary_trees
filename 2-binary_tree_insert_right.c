#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a new node to the right of a binary tree
 * @parent: the parent of the binary tree to be inserted to
 * @value: the value to be held by the new node
 * Return: the new node created.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL || parent == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;
	parent->right = new_node;

	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	return (new_node);
}
