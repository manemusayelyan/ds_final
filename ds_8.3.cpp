#include <iostream>
#include <queue>
using namespace std;

struct elem {
	int data;
	int left, right;
	elem(int d = 0, int l = 0, int r = 0)
		: data(d), left(l), right(r)
	{}
};


bool is_BSTree(elem* tree)
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (tree[curr].left)
		{
			if (tree[curr].data > tree[tree[curr].left].data)
				q.push(tree[curr].left);
			else
				return false;
		}
		if (tree[curr].right)
		{
			if (tree[curr].data <= tree[tree[curr].right].data)
				q.push(tree[curr].right);
			else
				return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	elem *tree = new elem[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> tree[i].data >> tree[i].left >> tree[i].right;
	cout << is_BSTree(tree);

	/*
	* n = 7 BSTree 
	* 
	* 10 2 3
	* 7 4 5
	* 14 6 7
	* 5 0 0
	* 8 0 0
	* 12 0 0
	* 15 0 0
	*/
	return 0;
}