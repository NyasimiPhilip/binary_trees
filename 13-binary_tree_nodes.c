#include "binary_trees.h"
/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 * Return: Number of nodes with at least 1 child in the tree0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + (tree->left || tree->right));
}
