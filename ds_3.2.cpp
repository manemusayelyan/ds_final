#include <iostream>
using namespace std;

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

Node* remove_target_nodes(Node* head, int target)
{
	if (head == nullptr)
		return nullptr;
	while (head && head->data == target)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}

	Node* cur_node = head;
	while (cur_node && cur_node->next)
	{
		if (cur_node->next->data == target)
		{
			Node* tmp = cur_node->next;
			cur_node->next = cur_node->next->next;
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
		tmp->next = create_node(arr[i]);
		tmp = tmp->next;
	}
	cout << "Original list\n";
	display_list(head);
	remove_duplicates(head);
	cout << "\nModified list : Removed all duplicates\n";
	display_list(head);

	return 0;
}