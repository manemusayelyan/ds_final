#include <iostream>
#include <queue>
using namespace std;
//5.3
struct treeNode {
	char data;
	treeNode* left, *right;
	treeNode(char d, treeNode* l = nullptr, treeNode* r = nullptr)
		: data(d), left(l), right(r)
	{}
};

bool is_expression(treeNode* root) {
	if (root == nullptr)
		return 0;

	queue<treeNode*> q;
	q.push(root);

	while (!q.empty()) {
		treeNode* curr = q.front();
		q.pop();
		if (curr->left != nullptr) {
			q.push(curr->left);
		}
		if (curr->right != nullptr) {
			q.push(curr->right);
		}

		if (curr->left == nullptr && curr->right == nullptr ) {
			if ((curr->data > 'Z' || curr->data < 'A') && (curr->data > 'z' || curr->data < 'a')) {
				return 0;
			}
		}
		else {
			if (curr->data != '+' && curr->data != '-' && curr->data != '*' && curr->data != '/') {
				return 0;
			}
		}
	}

	return 1;
}


int main() {
	treeNode* a = new treeNode('y');
	treeNode* b = new treeNode('x');
	treeNode* root = new treeNode('+', a, b);
	
	cout << is_expression(root) << endl;

	return 0;
}
