#include "binary_trees.h"
/* Declare print_at_level function before using it */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level);
/**
 * binary_tree_levelorder - Traverses a binary tree in level-order traversal
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	int height = binary_tree_height(tree);
	int level;

	for (level = 1; level <= height + 1; level++)
		print_at_level(tree, func, level);
}
/**
 * print_at_level - Prints nodes at a specific level of the binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Level to print.
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree || !func)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		print_at_level(tree->left, func, level - 1);
		print_at_level(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
