
/**
 * avl_insert - inserts a value
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int B;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if ((*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if ((*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	B = binary_tree_balance(*tree);

	if (B > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (B < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (B > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (B < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

