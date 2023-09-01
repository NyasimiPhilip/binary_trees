#include "binary_trees.h"

/**
 * struct queue_node_s - Queue node structure for level order traversal.
 * @node: Pointer to the binary tree node.
 * @next: Pointer to the next queue node.
 */
typedef struct queue_node_s
{
	binary_tree_t *node;
	struct queue_node_s *next;
} queue_node_t;

/**
 * create_queue_node - Creates a new queue node.
 * @node: Pointer to the binary tree node for the new queue node.
 *
 * Return: If an error occurs or malloc fails, returns NULL.
 *         Otherwise, returns a pointer to the new queue node.
 */
queue_node_t *create_queue_node(binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));
	if (new_node)
	{
		new_node->node = node;
		new_node->next = NULL;
	}
	return (new_node);
}

/**
 * free_queue - Frees a queue used for level order traversal.
 * @front: Pointer to the front of the queue.
 */
void free_queue(queue_node_t *front)
{
	queue_node_t *temp;
	while (front)
	{
		temp = front;
		front = front->next;
		free(temp);
	}
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	queue_node_t *queue = NULL;
	int flag = 0;

	queue_node_t *node = create_queue_node((binary_tree_t *)tree);
	if (!node)
		return (0);

	queue = node;

	while (node)
	{
		if (node->node->left)
		{
			if (flag)
			{
				free_queue(queue);
				return (0);
			}
			queue_node_t *left_node = create_queue_node(node->node->left);
			if (!left_node)
			{
				free_queue(queue);
				return (0);
			}
			node->next = left_node;
		}
		else
			flag = 1;

		if (node->node->right)
		{
			if (flag)
			{
				free_queue(queue);
				return (0);
			}
			queue_node_t *right_node = create_queue_node(node->node->right);
			if (!right_node)
			{
				free_queue(queue);
				return (0);
			}
			node->next = right_node;
		}
		else
			flag = 1;

		node = node->next;
	}

	free_queue(queue);
	return (1);
}
