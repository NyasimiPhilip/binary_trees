#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the
 * depth of the node in the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: First node.
 * @second: Second node.
 * Return: The lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_f = binary_tree_depth(first);
	size_t depth_s = binary_tree_depth(second);

	if (!first || !second)
		return (NULL);
	while (depth_f > depth_s)
	{
		first = first->parent;
		depth_f--;
	}
	while (depth_s > depth_f)
	{
		second = second->parent;
		depth_s--;
	}
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
