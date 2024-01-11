#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 9.3

struct treeNode
{
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int data, treeNode* left = nullptr, treeNode* right = nullptr)
		: data(data),
		left(left),
		right(right)
	{}
};

void print_lvlorder(treeNode* root)
{
	if (root == NULL)
		return;

	queue<treeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int count = q.size();
		stack<treeNode*> st;
		for (int i = 0; i < count; i++)
		{
			treeNode* cur_node = q.front();
				cout << cur_node->data << " ";
			q.pop();
			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);
		}
	}
	cout << endl;
}

void reverse_odd_lvls(treeNode* root)
{
	if (root == NULL)
		return;

	queue<treeNode*> q;
	q.push(root);
	int lvl = 0;
	while (!q.empty())
	{
		int count = q.size();
		stack<treeNode*> st;
			for (int i = 0; i < count; i++)
			{
				treeNode* cur_node = q.front();
				if (lvl % 2 == 0)
					cout << cur_node->data << " ";
				else
					st.push(cur_node);
				q.pop();

				if (cur_node->left)
					q.push(cur_node->left);

				if (cur_node->right)
					q.push(cur_node->right);
			}
			while (!st.empty())
			{
				cout << st.top()->data << " ";
				st.pop();
			}
			lvl++;
	}
}

int main()
{
	treeNode* d = new treeNode(6);
	treeNode* c = new treeNode(8);
	treeNode* b = new treeNode(7);
	treeNode* a = new treeNode(4);
	treeNode* e = new treeNode(5, b, c);
	treeNode* f = new treeNode(2, a);
	treeNode* g = new treeNode(3, e, d);
	treeNode* root = new treeNode(1, f, g);

	cout << "Levelorder traversal of given binary tree: ";
	print_lvlorder(root);
	cout << "Reverse odd levels of given binary tree: ";
	reverse_odd_lvls(root);
	return (0);
}