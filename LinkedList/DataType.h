typedef struct _Node Node;
struct _Node
{
	Node *prev;
	Node *next;
	void* value;
};

typedef struct
{
	Node *head;
	unsigned int dataSize;
} LinkedList;

typedef Node* Iterator;