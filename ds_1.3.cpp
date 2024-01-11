#include <iostream>
#include <queue>
using namespace std;
// 1.3
struct treeNode {
	char data;
	treeNode* left, * right;
	treeNode(int d, treeNode* l = nullptr, treeNode* r = nullptr)
		: data(d), left(l), right(r)
	{}
};

void construct_tree(treeNode* &root, char* pre, char* in, int pre_s, int in_s, int len) {
	if (len == 0)
		return;

	root = new treeNode(pre[pre_s]);

	int i;
	for (i = 0; i < len; ++i) {
		if (pre[pre_s] == in[in_s + i])
			break;
	}

	construct_tree(root->left, pre, in, pre_s + 1, in_s, i);
	construct_tree(root->right, pre, in, pre_s + i + 1, in_s + i + 1, len - 1 - i);
}

void print_tree_level_order(treeNode* root) {
	queue<treeNode*> q;
	q.push(root);

	while (!q.empty()) {
		treeNode* current = q.front();
		q.pop();

		cout << current->data << " ";

		if (current->left != nullptr) {
			q.push(current->left);
		}

		if (current->right != nullptr) {
			q.push(current->right);
		}
	}

}

int main() {
	char preorder[100], inorder[100];
	cin >> preorder >> inorder;

	treeNode* root;
	construct_tree(root, preorder, inorder, 0, 0, strlen(preorder));

	print_tree_level_order(root);

	return 0;
}
