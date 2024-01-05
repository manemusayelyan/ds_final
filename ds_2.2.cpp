#include <iostream>
using namespace std;

/*
*  2.2
*  Գրել ծրագիր, որը ներածում է մինչև 100 երկարության, անգլերեն փոքրատառերից բաղկացած
*  տող,պահում է տողի սիմվոլները ցուցակի մեջ, ապա յուրաքանչյուր բաղաձայնից առաջ ավելացնում է կետ,
*  վերջում հերթով արտածում է ցուցակի սիմվոլները։
*/

char str[101];

struct Node
{
	char data;
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

bool is_consonant(char c)
{
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y');
}

void insert_before_node(Node*& head, Node* target, char data)
{
	Node* cur_node = head;
	Node* prev = nullptr;

	while (cur_node && cur_node != target)
	{
		prev = cur_node;
		cur_node = cur_node->next;
	}

	if (cur_node == nullptr)
	{
		cout << "Node not found in the list.\n";
		return;
	}

	Node* new_node = create_node(data);
	new_node->next = cur_node;

	if (prev == nullptr)
		head = new_node;
	else
		prev->next = new_node;
}


void adding_dot_nodes_before_consonants(Node*& head)
{
	Node* cur_node = head;
	while (cur_node)
	{
		if (is_consonant(cur_node->data))
			insert_before_node(head, cur_node, '.');
		cur_node = cur_node->next;
	}
}

int main()
{
	cin.getline(str, 101, '\n');
	Node* head = create_node(str[0]);
	Node* tmp = head;
	int i = 1;
	while (str[i])
	{
		tmp->next = create_node(str[i]);
		tmp = tmp->next;
		i++;
	}
	cout << "Original list\n";
	display_list(head);
	cout << "\nModified list: Added '.' before consonants \n";
	adding_dot_nodes_before_consonants(head);
	display_list(head);
	return 0;
}