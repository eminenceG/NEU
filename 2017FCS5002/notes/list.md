# General Linear Lists
## Basic Operations
### Insertion
### Deletion
### Retrieval
### Traversal 	
## Implementation
### Array List
### Linked List
A **linked list** is a data structure that consists of sequence of nodes. Each node is composed of two fields: **data field** and **reference field** which is a pointer that points to the next node in the sequence.

We can model a node of the linked list using a structure as follows:

```
typedef struct node{
	int data;
	struct node* next;
} node;
```
#### Insertion
##### Add a node at the beginning of the linked list
First we declare a head pointer that always points to the first node of the list.

```
node *head;
```

We will need to create a new node each time we want to insert a new node into the list.

```
node *create(int data, node *next) {
	node *newNode = (node *) malloc(sizeof(node));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
        exit(0);
	}
	newNode->data = data;
	newNode->next = next;

	return newNode;
}
```

Second, we need to point the next to current head node and point head pointer to the new node.

```
node *prepend(node *head, int data) {
	node *newNode = create(data, head);
	head = newNode;

	return head;
}
```

##### Add a node at the beginning of the linked list

```
node *append(node *head, int data) {
	// go to the last node
	node *cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;

	// create a new node
	node *newNode = create(data, NULL);
	cursor->next = newNode;

	return head;
}
```

##### Insert a new node before a particular node
```
node *insertBefore(node *head, int data, node *nxt) {
	if (nxt == NULL || head == NULL)
		return NULL;

	if (head == nxt) {
		return prepend(head, data);
	}

	// find the prev node
	node *cursor = head;
	while (cursor != NULL) {
		if (cursor->next == nxt)
			break;
		cursor = cursor->next;
	}

	// nxt found
	if (cursor != NULL) {
		node *newNode = create(data, nxt);
		cursor->next = newNode;
		return head;
	}
	else { // nxt not found
		return NULL;
	}
}
```


#### Traverse
To traverse the linked list, we start from first node, and move to the next node until we reach a NULL pointer.

```
// a function pointer that points to a function for linked list node manipulation
typedef void (*callback)(node* data);

void traverse(node *head, callback f) {
	node *cursor = head;
	while (cursor != NULL) {
		f(cursor);
		cursor = cursor->next;
	}
}
```

##### Count the elements of the linked list

```
int count(node *head) {
	node *cursor = head;
	int c = 0;
	while (cursor != NULL) {
		c++;
		cursor = cursor->next;
	}
	return c;
}
```

##### Reverse linked list
```
node *reverse(node *head) {
	node *prev = NULL;
	node *current = head;
	node *next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}
```


#### Retrieval

##### search for a node

```
node *search(node *head, int data) {
	node *cursor = head;
	while (cursor != NULL) {
		if (cursor->data == data) // node found
			return cursor;
		cursor = cursor->next;
	}
	// node not found
	return NULL;
}
```

#### Deletion
##### Delete a node from the front of the linked list

```
node *removeFront(node *head) {
	if (head == NULL)
		return NULL;
	node *front = head;
	head = head->next;
	front->next = NULL;
	free(front);

	return head;
}
```

##### Delete a node from the back of the linked list
```
node *removeBack(head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	node *cursor = head;
	node *back = NULL;
	while (cursor->next != NULL) {
		back = cursor;
		cursor = cursor->next;
	}
	back->next = NULL;
	free(cursor);

	return head;
}
```

##### Delete a node in the middle of the linked list
```
node *remove(node *head, node *nd) {
	if (nd == head) {
		return removeFront(head);
	}
	if (nd->next == NULL)
		return removeBack(head);
	node *cursor = head;
	while (cursor != NULL) {
		if (cursor -> nd) {
			break;
		}
		cursor = cursor->next;
	}
	if (cursor != NULL) { // node found
		node *tmp = cursor->next;
		cursor->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}			e
	// if node not found, do nothing
	return head;
}
```
