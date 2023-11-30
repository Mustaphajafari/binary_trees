#include "binary_trees.h"

/**
 * is_complete - Check if a binary tree is complete
 * @root: Pointer to the root node of the tree
 * @index: Current index of the node in the tree
 * @nodes: Number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *root, int index, int nodes)
{
    if (root == NULL)
        return (1);

    if (index >= nodes)
        return (0);

    return (is_complete(root->left, 2 * index + 1, nodes) &&
            is_complete(root->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!is_complete(tree, 0, binary_tree_size(tree)))
        return (0);

    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);

    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

