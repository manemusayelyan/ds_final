#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 10.3

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode(int d, treeNode* l = nullptr, treeNode* r = nullptr)
		:data(d), left(l), right(r) {}
};

void addToBSTree(treeNode*& root, int elem)
{
	if (root == nullptr)
	{
		root = new treeNode(elem);
		return;
	}
	if (root->data > elem)
		addToBSTree(root->left, elem);
	else
		addToBSTree(root->right, elem);
}

void inorder_recursive(treeNode* root)
{
	if (root == nullptr)
		return;
	inorder_recursive(root->left);
	cout << root->data << " ";
	inorder_recursive(root->right);
}


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	treeNode* root = nullptr;
	for (int i = 0; i < n; i++)
		addToBSTree(root, arr[i]);
	arr.clear();
	inorder_recursive(root);

	return 0;
}