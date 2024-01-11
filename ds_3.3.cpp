#include <iostream>
#include <queue>
using namespace std;

// 3.3

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

int get_breadth(treeNode* root)
{
	treeNode* tmp = root;
	queue<treeNode*> q;
	q.push(tmp);

	int count_nodes = 1;
	int t = 0;
	int max = 1;

	while (!q.empty())
	{
		t = 0;
		for (int i = 0; i < count_nodes; i++)
		{
			tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				q.push(tmp->left);
				t++;
			}
			if (tmp->right)
			{
				q.push(tmp->right);
				t++;
			}
		}
		count_nodes = t;
		if (count_nodes > max)
			max = count_nodes;
	}
	return max;
}

int main()
{
	treeNode* g = new treeNode(13);
	treeNode* f = new treeNode(11);
	treeNode* e = new treeNode(12);
	treeNode* d = new treeNode(10);
	treeNode* c = new treeNode(8, g);
	treeNode* a = new treeNode(4, c, d);
	treeNode* b = new treeNode(6, e, f);
	treeNode* root = new treeNode(5, a, b);

	cout << "Breadth of the given binary tree is: " << get_breadth(root) << endl;
	return 0;
}

