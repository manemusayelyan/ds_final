#include <iostream>
using namespace std;

/*
*  16.2
*  Գրել Ֆունկցիա, որը զանգվածի միջոցով ներկայացված երկկապ ցուցակում յուրաքանչյուր, տարրից թողնում է մեկական նմուշ։
*/

int arr[1000];

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* create_node(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	return new_node;
}

void display_list_forward(Node* node)
{
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

void display_list_backward(Node* node)
{
	while (node && node->next)
	{
		node = node->next;
	}

	while (node)
	{
		cout << node->data << " ";
		node = node->prev;
	}
}

Node* remove_target_nodes(Node* head, int target)
{
	if (head == nullptr)
		return nullptr;

	while (head && head->data == target)
	{
		Node* tmp = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		delete tmp;
	}

	Node* cur_node = head;
	while (cur_node && cur_node->next)
	{
		if (cur_node->next->data == target)
		{
			Node* tmp = cur_node->next;
			cur_node->next = cur_node->next->next;
			if (cur_node->next)
				cur_node->next->prev = cur_node;
			delete tmp;
		}
		else
			cur_node = cur_node->next;
	}
	return head;
}

void remove_duplicates(Node* head)
{
	if (!head)
		return;

	Node* cur_node = head;
	while (cur_node)
	{
		cur_node->next = remove_target_nodes(cur_node->next, cur_node->data);
		cur_node = cur_node->next;
	}
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
		Node* new_node = create_node(arr[i]);
		tmp->next = new_node;
		new_node->prev = tmp;
		tmp = tmp->next;
	}

	cout << "Original list (forward)\n";
	display_list_forward(head);

	remove_duplicates(head);

	cout << "\nModified list : Removed all duplicates (forward)\n";
	display_list_forward(head);

	return 0;
}
