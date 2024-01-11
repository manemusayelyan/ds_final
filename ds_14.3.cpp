#include <iostream>
using namespace std;

//14.3
struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode(int d, treeNode* l = nullptr, treeNode* r = nullptr)
		: data(d), left(l), right(r) {}
};

int NumOfNodesInGivenLvl(treeNode* root, int lvl, int k)
{
	if (root == nullptr)
		return 0;
	if (lvl < k)
		return NumOfNodesInGivenLvl(root->left, lvl + 1, k) + NumOfNodesInGivenLvl(root->right, lvl + 1, k);
	return 1;
}

int main()
{
	treeNode* c = new treeNode(42);
	treeNode* b = new treeNode(13);
	treeNode* a = new treeNode(7, c);
	treeNode* root = new treeNode(10, a, b);

	cout << "Number of nodes in k-th level: " << NumOfNodesInGivenLvl(root, 0, 0);
	return (0);
}