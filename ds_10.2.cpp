#include <iostream>
#include <stack>
using namespace std;

/*
* 10.2
* Գրել ֆունկցիա որը շրջում է միակապ ցուցակի տարրերի դասավորությունը։
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

void reverse_list(Node** head)
{
	if (!*head)
		return;
	stack<Node*> st;
	Node* tmp = *head;
	while (tmp->next)
	{
		st.push(tmp);
		tmp = tmp->next;
	}
	*head = tmp;
	while (!st.empty())
	{
		tmp->next = st.top();
		st.pop();
		tmp = tmp->next;
	}
	tmp->next = NULL;
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
	reverse_list(&head);
	cout << "\nReversed linked list\n";
	display_list(head);
	return 0;
}