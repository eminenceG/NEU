## C Memory Management
When a C program is loaded, it is organized into areas of memory, called segments:
- Program Code
- Constants
- Global and static variables
- Dynamic memory (heap)
- Local vatiables (stack)


	Publisher* getPublisherByName(const char* name, Publisher* pub)
	{
		strcpy(pub->name, name);
		return pub;
	}

	int main(void) {
		Publisher pubSpace;
		Publisher *pub = getPublisherByName("National Geographic", &pubSpace);
		printPublisher(pub);
		return EXIT_SUCCESS;
	}
### malloc
The function **malloc** and calloc obtain blocks of memory dynamically.

	void *malloc(size_t n)

### calloc
returns a pointer to n bytes of uninitialized storage, or NULL if the request cannot be satisfied.

	void *calloc(size_t n, size_t size)

returns a pointer to enough free space for an array of n objects of the specialized size, or NULL if the request cannot be satisfied.

### free
**free(p)** frees the space pointed to by p, where p was originally obtained by a call to **malloc** or **calloc**.

### realloc
you can increase or decrease the size of an allocated memory block by calling the function **realloc()**.


 	/** size of publishers array */
 	const size_t PUBLISHERS_SIZE = 4;

	/** Array of existing publishers */
	Publisher *publishers[PUBLISHERS_SIZE] = {NULL};

	int main(void) {
		Publisher *pub = getPublisherByName("National Geographic", NULL);
		printPublisher(pub);
		free(pub);
		pub = NULL;

		return EXIT_SUCCESS;
	}

	initially set PUBLISHERS_SIZE to a power of 2, and double it if more space is required.

		if (pub == NULL) {
			if (pindex +1 >= PUBLISHERS_SIZE) {
				PUBLISHERS_SIZE *= 2;
				publishers = realloc(publishers, PUBLISHERS_SIZE * sizeof(Publisher*));
			}
			pub = malloc(sizeof(Publisher));
			publishers[pindex] = pub;
			publishers[++pindex] = NULL;
		}
