//============================= Structures =============================//

/*
* Binary Tree Node Structure
* The node has two links which points to left and right children
* along with data field.
*/
typedef struct BinaryTreeNode {	
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
} BinaryTreeNode;

//============================= Operations =============================//

/* CONTENT
* 1. Inserting an element into a tree
* 2. Deleting an element from a tree
* 3. Searching for an element
* 4. Traversing the tree 
*    4.1 Preorder (DLR) Traversal
*    4.2 Inorder (LDR) Traversal
*    4.3 PostOrder (LRD) Traversal
*	 4.4 Breadth First Traversal(BFS)
*
*/


/*
* ************************* Preorder Traversal **************************
*
* Each node is processed before(pre) either of its subtrees
* Preorder Traversal is defined as follows: 
* 	1. Visit the root
* 	2. Traverse the left subtree in Preorder
*	3. Traverse the right subtree in Preorder
*/
void preOrder(BinaryTreeNode *root) {
	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// Non-recursive Version
void preOrderNonRecursive(BinaryTreeNode *root) {
	Stack *s = createStack();
	while (1) {
		while (root) {
			printf("%d", root->data);
			push(s, root);
			root = root->left;
		}
		if (isEmptyStack(s))
			break;
		root = pop(s);
		root = root->right;
	}
	deleteStack(s);	
}

/*
* ************************** Inorder Traversal ***************************
*
* Each node is processed between(in) either of its subtrees
* Preorder Traversal is defined as follows: 
* 	1. Traverse the left subtree in Preorder
* 	2. Visit the root
*	3. Traverse the right subtree in Preorder
*/
void inOrder(BinaryTreeNode *root) {
	if (root) {
		preorder(root->left);
		printf("%d", root->data);
		preorder(root->right);
	}
}

// Non-recursive Version
void preOrderNonRecursive(BinaryTreeNode *root) {
	Stack *s = createStack();
	while (1) {
		while (root) {
			push(s, root);			
			root = root->left;
		}
		if (isEmptyStack(s))
			break;
		root = pop(s);
		printf("%d", root->data);
		root = root->right;
	}
	deleteStack(s);	
}

/*
* ************************** Postorder Traversal ***************************
*
* Each node is processed after(post) both its subtrees
* Preorder Traversal is defined as follows: 
* 	1. Traverse the left subtree in Preorder
* 	2. Traverse the right subtree in Preorder
*	3. Visit the root
*/
void postOrder(BinaryTreeNode *root) {
	if (root) {
		preorder(root->left);
		preorder(root->right);
		printf("%d", root->data);
	}
}

// Non-recursive Version
void postOrderNonRecursive(BinaryTreeNode *root) {
	Stack *s = createStack();
	BinaryTreeNode *previous = NULL;
	do {
		while (root != NULL) {
			push(s, root);
			root = root->left;
		}
		while (root == NULL && !isEmptyStack(s)) {
			root = top(s);
			if (root->right == NULL || root->right == previous) {
				printf("%d", root->data);
				pop(s);
				previous = root;
				root = NULL;
			}
			else {
				root = root->right;
			}
		}
	} while (!isEmptyStack(s));
}

/*
* *********************** Level Order Traversal ************************
*
* Level order Traversal is defined as follows:
*	1. Visit the root
* 	1. While traversing level n, keep all the elements at level n+1 in queue
* 	2. Go to the next level and visit all the nodes at that level
*	3. Repeat this until all levels are completed
*/
void levelOrder(BinaryTreeNode *root) {
	BinaryTreeNode *temp;
	Queue *q = createQueue();
	if (!root)
		return
	enQueue(q, root);
	while (!isEmptyQueue(q)) {
			temp = deQueue(q);
		ptrint("%d", temp->data);
		if (temp->left)
			enQueue(q, temp->left);
		if (temp->right)
			enQueue(q, temp->right);
	}
	deleteQueue(q);
}

// Non-recursive Version
void postOrderNonRecursive(BinaryTreeNode *root) {
	Stack *s = createStack();
	BinaryTreeNode *previous = NULL;
	do {
		while (root != NULL) {
			push(s, root);
			root = root->left;
		}
		while (root == NULL && !isEmptyStack(s)) {
			root = top(s);
			if (root->right == NULL || root->right == previous) {
				printf("%d", root->data);
				pop(s);
				previous = root;
				root = NULL;
			}
			else {
				root = root->right;
			}
		}
	} while (!isEmptyStack(s));
}