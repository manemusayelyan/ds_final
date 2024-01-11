#include <iostream>
#include <stack>
#include <queue>
using namespace std;

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


void reversed_levelorder(treeNode* root)
{
	if (root == NULL)
		return;

	queue<treeNode*> q;
	q.push(root);
	stack<treeNode*> st;
	while (!q.empty())
	{
		treeNode* cur_node = q.front();
		st.push(cur_node);
//		cout << cur_node->data << " ";
		q.pop();
		if (cur_node->right)
			q.push(cur_node->right);
		if (cur_node->left)
			q.push(cur_node->left);
	}
	cout << endl;
	while (!st.empty())
	{
		cout << st.top()->data << " ";
		st.pop();
	}
}


void print_levelorder(treeNode* root)
{
	if (root == NULL)
		return;

	queue<treeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		treeNode* cur_node = q.front();
		cout << cur_node->data << " ";
		q.pop();
		if (cur_node->left)
			q.push(cur_node->left);
		if (cur_node->right)
			q.push(cur_node->right);
	}
	cout << endl;
}

int main()
{
	treeNode* d = new treeNode(6);
	treeNode* c = new treeNode(4);
	treeNode* b = new treeNode(8);
	treeNode* a = new treeNode(7);
	treeNode* e = new treeNode(5, a, b);
	treeNode* f = new treeNode(2, c);
	treeNode* g = new treeNode(3, e, d);
	treeNode* root = new treeNode(1, f, g);

	print_levelorder(root);
	reversed_levelorder(root);
	return (0);
}