#include <iostream>
#include <queue>
using namespace std;

// Խնդիր 2.3

struct elem
{
	int data;
	int left;
	int right;
	elem(int data = 0, int left = 0, int right = 0)
		:data(data),
		right(right),
		left(left)
	{}
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Build(int n);
	//void Print();
	int  GetTreeHeight();
	int	 GetNumOfLeaves();
private:
	elem* tree;
};

BinaryTree::BinaryTree()
{
	tree = nullptr;
}

BinaryTree::~BinaryTree()
{
	delete[] tree;
}

void BinaryTree::Build(int n)
{
	tree = new elem[n + 1];
	for (int i = 1; i <= n; i++)
	{
		if (2 * i <= n)
			tree[i].left = 2 * i;
		else
			tree[i].left = 0;
		if (2 * i <= n - 1)
			tree[i].right = 2 * i + 1;
		else
			tree[i].right = 0;
		tree[i].data = i;
	}
}

int BinaryTree::GetNumOfLeaves()
{
	int count_leaves = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (tree[cur].left)
			q.push(tree[cur].left);
		if (tree[cur].right)
			q.push(tree[cur].right);
		if (tree[cur].left == 0 && tree[cur].right == 0)
			count_leaves++;
	}
	return count_leaves;
}

int BinaryTree::GetTreeHeight()
{
	int hegiht = 0;
	queue<int> q;
	q.push(1);
	q.push(0);

	while (q.size() > 1)
	{
		int cur = q.front();
		q.pop();
		if (cur == 0)
		{
			hegiht++;
			q.push(0);
		}
		else {
			if (tree[cur].left)
				q.push(tree[cur].left);

			if (tree[cur].right)
				q.push(tree[cur].right);
		}
	}
	return hegiht;
}

int main()
{
	BinaryTree t;
	t.Build(9);
	cout << "The height of given Binary tree is: " << t.GetTreeHeight() << endl;
	cout << "Number of leaves of given binary tree is : " << t.GetNumOfLeaves() << endl;
}
