#include <stdio.h>
#include <stdlib.h>

typedef int ListDataType;
typedef struct Node_t {
	ListDataType data;
	struct Node* next;
} Node;
typedef struct List_t {
	struct Node* head;
} List;

// Creates a node
Node* CreateNode(ListDataType data)
{
	Node* newNode = malloc(sizeof(Node));
	if (!newNode) 
	{
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Creates a list with empty header
List* CreateList()
{
	List* list = malloc(sizeof(List));
	list->head = CreateNode(NULL);
	return list;
}

//Returns list head
Node* GetListHead(List* list)
{
	return list->head;
}
//Returns next node of node
Node* GetNextNode(Node* node)
{
	return node->next;
}
//Returns value of node
ListDataType GetValue(Node* node)
{
	return node->data;
}
//Inserts value after node of linked list
Node* Insert(Node* after, ListDataType newValue) {
	Node* next = after->next;
	Node* newNode = CreateNode(newValue);
	newNode->next = next;
	after->next = newNode;
}
//Frees linked list
void FreeList(List* list)
{
	Node* current = list->head;
	Node* next = current;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}
//Pushes at the front of linked list
Node* PushFront(List* list, ListDataType newValue)
{
	Node* newHead = CreateNode(newValue);
	newHead->next = GetListHead(list);
	list->head = newHead;
	return newHead;
}
//Pushes at the back of linked list
Node* PushBack(List* list, ListDataType newValue)
{
	Node* node = CreateNode(newValue);
	Node* current = GetListHead(list);
	while (GetNextNode(current) != NULL) {
		current = current->next;
	}
	current->next = node;
	return node;
}
//Pops front value of list, returning it. 
ListDataType PopFront(List* list)
{
	Node* head = list->head;
	list->head = head->next;
	ListDataType data = GetValue(head);
	free(head);
	return data;
}
//Returns size of list
size_t GetListSize(List* list) {
	Node* head = list->head;
	size_t size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}
//Finds first occurence of value in list and returns a pointer to it
Node* FindInList(List* list, ListDataType value)
{
	Node* current = list->head;
	while (current) {
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}
//Deletes list node
void DeleteListNode(List* list, Node* target)
{
	Node* current = list->head;
	if (current == target)
	{
		PopFront(list);
	}
	else
	{
		while (current)
		{
			if (current->next == target)
			{
				Node* next = GetNextNode(target);
				current->next = next;
				free(target);
			}
			current = current->next;
		}
	}
}
//Finds element by value and deletes it
void DeleteListValue(List* list, ListDataType value)
{
	Node* target = FindInList(list, value);
	if (target) {
		DeleteListNode(list, target);
	}
}
//Prints list
void PrintList(List* list)
{
	Node* head = list->head;
	while (head->next) {
		printf("%d", GetValue(head));
		head = head->next;
	}
	printf("%d", GetValue(head));
}


int main() {
	List* a = CreateList();
	PushBack(a, 5);
	PushFront(a, 4);
	Node* n = FindInList(a, 5);
	Insert(n, 8);
	//DeleteListNode(a, n);
	//DeleteListValue(a, 8);
	//printf("%d", GetValue(GetNextNode(n)));
	//ListDataType i = PopFront(a);
	PrintList(a);
	//printf("%d", GetListSize(a));
	//printf("%d", GetValue(GetListHead(a)));
}