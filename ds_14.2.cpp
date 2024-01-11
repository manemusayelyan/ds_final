#include <iostream>
using namespace std;

char arr1[1000];
char arr2[1000];

struct Node
{
	char data;
	struct Node* next;
	Node(char d, Node* next = nullptr)
		:data(d)
	{}
};

Node* listcmp(Node** head1, Node** head2)
{
	if (*head1 == nullptr && *head2 == nullptr)
		return NULL;
	Node* tmp1, *tmp2;
	tmp1 = *head1;
	tmp2 = *head2;
	while (tmp1 && tmp2)
	{
		if (tmp1->data > tmp2->data)
			return (*head1);
		else if (tmp1->data < tmp2->data)
			return (*head2);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return NULL;
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int j = 0; j < n; j++)
		cin >> arr2[j];
	Node* head1 = new Node(arr1[0]);
	Node* head2 = new Node(arr2[0]);
	Node *tmp = head1;
	for (int i = 1; i < n; i++)
	{
		tmp->next = new Node(arr1[i]);
		tmp = tmp->next;
	}
	tmp = head2;
	for (int i = 1; i < n; i++)
	{
		tmp->next = new Node(arr2[i]);
		tmp = tmp->next;
	}

	if (listcmp(&head1, &head2)->data == head1->data)
	{
		cout << "first list";
	}
	else if (listcmp(&head1, &head2)->data == head2->data)
		cout << "Second list";
	else
		cout << "Are equal";
	return 0;
}