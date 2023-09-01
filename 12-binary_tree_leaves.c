#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->left && !node->right);
}
/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * @tree: Pointer to the root node of the tree to count leaves.
 * Return: Number of leaves in the tree, 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
