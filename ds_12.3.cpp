#include <iostream>
#include <stack>
using namespace std;

//12.3

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode(int d, treeNode* l = nullptr, treeNode* r = nullptr)
		:data(d),
		left(l),
		right(r){}
};

bool binarytreecmp(treeNode* root1, treeNode* root2)
{
	if (root1 == nullptr || root2 == nullptr)
		return false;
	stack<treeNode *> st1;
	stack<treeNode *> st2;
	st1.push(root1);
	st2.push(root2);
	while (!st1.empty() && !st2.empty())
	{
		treeNode* cur1 = st1.top();
		treeNode* cur2 = st2.top();

		st1.pop();
		st2.pop();
		if ((cur1->right && cur2->right) || (!cur1->right && !cur2->right))
		{
			if (cur1->right && cur2->right)
			{
				st1.push(cur1->right);
				st2.push(cur2->right);
			}
		}
		else
			return false;
		if ((cur1->left && cur2->left) || (!cur1->left && !cur2->left))
		{
			if (cur1->left && cur2->left)
			{
				st1.push(cur1->left);
				st2.push(cur2->left);
			}
		}
		else
			return false;

	}
	return true;
}

int main()
{
	treeNode* a2 = new treeNode(14);
	treeNode* a1 = new treeNode(7);
	treeNode* root1 = new treeNode(10, a1, a2);

	treeNode* b2 = new treeNode(11);
	treeNode* b1 = new treeNode(13);
	treeNode* root2 = new treeNode(15, b1);

	cout << binarytreecmp(root1, root2);

	return 0;
}