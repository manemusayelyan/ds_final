#include <iostream>
using namespace std;

/* 6.2
*  Գրել ծրագիր որը կառուցում է դրական ամբողջ թվերի ցուցակ,
*  ապա ցուցակից հեռացնում է մեծագույն տարրը պարունակող բոլոր հանգույցները։
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

void remove_nodes_with_max_val(Node* head, int max)
{
	if (head == nullptr)
		return;
	while (head && head->data == max)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	Node* cur_node = head;
	while (cur_node && cur_node->next)
	{
		if (cur_node->next->data == max)
		{
			Node* tmp = cur_node->next;
			cur_node->next = cur_node->next->next;
			delete tmp;
		}
		else
			cur_node = cur_node->next;
	}
}
int main()
{
	int max;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> arr[i];
	max = arr[0];
	Node* head = create_node(arr[0]);
	Node* tmp = head;
	for (int i = 1; i < t; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		tmp->next = create_node(arr[i]);
		tmp = tmp->next;
	}
	cout << "Original list\n";
	display_list(head);
	remove_nodes_with_max_val(head, max);
	cout << "\nModified list : Removed all max value nodes\n";
	display_list(head);

	return 0;
}