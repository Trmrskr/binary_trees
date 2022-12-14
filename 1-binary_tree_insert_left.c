#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node to the left of a binary tree
 * @parent: the parent of the binary tree to be inserted to
 * @value: the value to be held by the new node
 * Return: the new node created.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL || parent == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;
	parent->left = new_node;

	if (new_node->left != NULL)
		new_node->left->parent = new_node;

	return (new_node);
}
