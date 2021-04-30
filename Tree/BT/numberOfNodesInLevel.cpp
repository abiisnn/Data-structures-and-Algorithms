#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node *left, *right;
	int data;
    Node(int v, Node* l = NULL, Node* r = NULL) : data(v), left(l), right(r) {}
};

int numberOfNodesInLevel(Node *root, int level) {
	if(root == NULL) return 0;
	queue<pair<Node *, int>> bfs; // first: Nodo en el que estoy
	bfs.push(make_pair(root, 0)); // level = 0

	int numberOfNodes = 0;
	while(!bfs.empty()) {
		pair<Node *, int> current = bfs.front();
		bfs.pop();

		if(current.second == level) {
			numberOfNodes++;
		}
		if(current.second > level) {
			break;
		}
		// Insert my children
		if(current.first->left != NULL) {
			bfs.push(make_pair(current.first->left, current.second + 1));
		}
		if(current.first->right != NULL) {
			bfs.push(make_pair(current.first->right, current.second + 1));
		}
	}
	return numberOfNodes;
}
int main() {
	vector<Node *> nodes;

	for(int i = 0; i < 11; i++) {
		Node *element = new Node(i);
		nodes.push_back(element);
	}
	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[2];
	nodes[1]->left = nodes[3];
	nodes[1]->right = nodes[4];
	nodes[4]->left = nodes[7];
	nodes[4]->right = nodes[8];
	nodes[2]->left = nodes[5];
	nodes[2]->right = nodes[6];
	nodes[5]->left = nodes[9];
	nodes[9]->left = nodes[10];

	cout << "number of nodes in level: " << numberOfNodesInLevel(nodes[0], 10) << endl;
}