#include <iostream>
using namespace std;

/*
*  Տոմս 1 ։ խնդիր 2
*  Գրել ծրագիր, որը ներածում է մինչև 100 երկարության, անգլերեն փոքրատառերից բաղկացած,
*  տող,պահում է տողի սիմվոլները ցուցակի մեջ, ապա հեռացնում է ձայնավորները, 
*  վերջում արտածում է ցուցակում մնացած սիմվոլները։
*/

// English alphabet vowels  a, e, i, o, u, y

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

bool is_vowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

void remove_nodes(Node*& head)
{
	Node* cur_node = head;
	Node* prev = nullptr;

	while (cur_node)
	{
		Node* temp = cur_node;
		if (is_vowel(cur_node->data))
		{
			if (!prev)
			{
				head = cur_node->next;
				cur_node = head;
			}
			else
			{
				prev->next = cur_node->next;
				cur_node = cur_node->next;
			}

			delete temp;
		}
		else
		{
			prev = cur_node;
			cur_node = cur_node->next;
		}
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
	cout << "\nModified list: Removed all vowels\n";
	remove_nodes(head);
	display_list(head);
	return 0;
}