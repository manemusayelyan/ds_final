#include <iostream>
using namespace std;

/*
* 8.2
* Գրել ծրագիր, որը կարգավորում էմիակապ ցուցակի տարրերը չնվազման կարգով։
*/

int arr[1000];

struct Node
{
	int data;
	Node* next;
};

Node* create_node(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = nullptr;
	return new_node;
}

void display_list(Node* node)
{
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

Node* merge(Node* a, Node* b)
{
	Node* res = nullptr;
	if (a == nullptr)
		return (b);
	else if (b == nullptr)
		return (a);
	if (a->data <= b->data)
	{
		res = a;
		res->next = merge(a->next, b);
	}
	else
	{
		res = b;
		res->next = merge(a, b->next);
	}

	return (res);
}

void front_back_split(Node* src, Node** front_ref, Node** back_ref)
{
	Node* fast;
	Node* slow;
	slow = src;
	fast = src->next;

	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = src;
	*back_ref = slow->next;
	slow->next = NULL;
}

void sort_list(Node** head_ref)
{
	Node* head = *head_ref;
	Node* a;
	Node* b;

	if (head == nullptr || head->next == nullptr)
		return;
	front_back_split(head, &a, &b);
	sort_list(&a);
	sort_list(&b);
	*head_ref = merge(a, b);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> arr[i];
	Node* head = create_node(arr[0]);
	Node* tmp = head;
	for (int i = 1; i < t; i++)
	{
		tmp->next = create_node(arr[i]);
		tmp = tmp->next;
	}
	cout << "Original list\n";
	display_list(head);
	sort_list(&head);
	cout << "\nSorted list\n";
	display_list(head);
	return 0;
}