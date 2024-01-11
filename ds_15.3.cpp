#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 15.3
struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode(int d, treeNode* l = nullptr, treeNode* r = nullptr)
		: data(d), left(l), right(r) {}
};

bool FindPath(treeNode* root, vector<int>& path, int target)
{
	if (root == nullptr)
		return false;
	stack<treeNode*> st;
	st.push(root);

	treeNode* cur = st.top();
	treeNode* last_visited = nullptr;

	while (cur || !st.empty())
	{
		while (cur)
		{
			path.push_back(cur->data);
			if (cur->data == target)
				return true;
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		if (cur->right && cur->right != last_visited)
			cur = cur->right;
		else
		{
			st.pop();
			last_visited = cur;
			path.pop_back();
			cur = nullptr;
		}
	}
	return false;
}

int main()
{
	treeNode* a = new treeNode(5);
	treeNode* b = new treeNode(8);
	treeNode* c = new treeNode(12);
	treeNode* d = new treeNode(15);
	treeNode* e = new treeNode(7, a, b);
	treeNode* f = new treeNode(14, c, d);
	treeNode* root = new treeNode(42, e, f);

	vector<int> path;
	if (FindPath(root, path, 8))
	{
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
	}
	return 0;
}