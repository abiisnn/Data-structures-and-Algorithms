#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* left, *right;
    int data;
    Node(int v, Node* l = NULL, Node* r = NULL) : data(v), left(l), right(r) {}
};

// Bfs O(v + e)
int numberOfNodesInLevel(Node *root, int level) {
	if(root == NULL) return 0;
	queue<pair<Node *, int>> bfs; // Current node, level
	bfs.push_back(make_pair(root, 0));
	
	int numberOfNodes = 0;
	while(!bfs.empty()) {
		pair<Node *, int> current = bfs.top();
		bfs.pop();
		if(current.second == level) {
			numberOfNodes++;
		}
		// Insert elements
		if(current.first->left) {
			bfs.push_back(make_pair(current.first->left), current + 1);
		}
		if(current.first->right) {
			bfs.push_back(make_pair(current.first->right), current + 1);
		}
	}
	return numberOfNodes;
}

int main() {
	vector<Node *> nodes;
	for(int i = 0; i < 11; i++) {
		Node *ele = new Node(i);
		nodes.push_back(ele);
	}
	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[2];
	nodes[1]->left = nodes[3];
	nodes[3]->left = nodes[4];
	nodes[3]->right = nodes[5];
	nodes[5]->left = nodes[6];

	int nodesInLevel = numberOfNodesInLevel(nodes[0], 4);
}