#include <iostream>
using namespace std;

/*
* 11.2
* Մեծ քանակությամբ զրոներ պարունակող մատրիցը անվանենք նոսր մատրից։
* Ներկայացնել նոսր մատրիցը երկկապ ցուցակի միջոցով, յուրաքանչյուր հանգույցում պահելով մատրիցի մի ոչ զրոյական տարրի
* արժեքը, տողի կարգահամարը, սյան կարգահամարը։Իրականացնել երկու n չափանի քռակուսի նոսր մատրիցների գումար։
*/

struct Item
{
	int val;
	int row;
	int col;
};

struct Node
{
	Item* data;
	Node* next;
};

Item* create_item(int val, int row, int col)
{
	Item* new_item = new Item();
	new_item->val = val;
	new_item->row = row;
	new_item->col = col;

	return new_item;
}

Node* create_node(int data, int row, int col)
{
	Node* new_node = new Node();
	Item* item = create_item(data, row, col);
	new_node->data = item;
	new_node->next = nullptr;
	return new_node;
}

void display_list(Node* node)
{
	while (node != nullptr)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

Node* fill_list(int matrix[3][3], Node* head, int n)
{
	Node* tmp = nullptr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j])
			{
				if (head == nullptr)
				{
					head = create_node(matrix[i][j], i, j);
					tmp = head;
				}
				else
				{
					tmp = tmp->next = create_node(matrix[i][j], i, j);
				}
			}
		}
	}
	return head;
}


void sum_of_lists(Node* first, Node* second, int res_matrix[3][3])
{
	Node* tmp = second;

	while (first)
	{
		while (tmp)
		{
			if (first->data->col == tmp->data->col && first->data->row == tmp->data->row)
			{
				int sum = first->data->val + tmp->data->val;
				res_matrix[first->data->row][first->data->col] = sum;
			}
			tmp = tmp->next;
		}
		tmp = second;
		first = first->next;
	}

}
int main()
{
	int n = 3;
	int res_matrix[3][3] = {0};
	int first_matrix[3][3] = {	
		{1, 0, 1},
		{0, 0, 2},
		{7, 0, 3}};

	int second_matrix[3][3] = {
	{0, 0, 1},
	{5, 0, 2},
	{1, 0, 2}};
	Node* head_first = nullptr;
	Node* head_second = nullptr;
	head_first = fill_list(first_matrix, head_first, n);
	head_second = fill_list(second_matrix, head_second, n);

	sum_of_lists(head_first, head_second, res_matrix);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res_matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}