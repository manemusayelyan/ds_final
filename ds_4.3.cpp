#include <iostream>
#include <queue>
using namespace std;

//4.3

struct treeNode {
	int data;
	int left, right;
	treeNode(int d = -1, int l = -1, int r = -1)
		: data(d), left(l), right(r)
	{}
};

int get_binarytree_height(treeNode* tree, int root) {
	if (root == -1)
		return 0;

	queue<int> q;
	q.push(root);
	q.push(-1);
	int h = 1;

	while (q.size() > 1) {
		int curr = q.front();
		q.pop();
		if (curr == -1) {
			q.push(-1);
			h++;
		}
		else {
			if (tree[curr].left != -1) {
				q.push(tree[curr].left);
			}
			if (tree[curr].right != -1) {
				q.push(tree[curr].right);
			}
		}
	}

	return h;
}


int main() {
	int n, tmp, root = -1;
	cin >> n;
	treeNode* tree = new treeNode[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > -1) {
			if (tree[tmp].left == -1)
				tree[tmp].left = i;
			else
				tree[tmp].right = i;
		}
		else {
			root = i;
		}
		tree[i].data = i;
	}

	cout << get_binarytree_height(tree, root) << endl;

	return 0;
}
