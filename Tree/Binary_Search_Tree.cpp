#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left, *right;
    int data;
    Node(int v, Node* l = NULL, Node* r = NULL) : data(v), left(l), right(r) {}
};

struct BST {
	Node *root;
	BST(Node *r = NULL): root(r) {}

	/* Recursive function that add an new element in
	   a Binary Search Tree. */
	void insertElement(Node *&node, int n) {
		if(!node) {
			Node *newElement = new Node(n);
			node = newElement;
			return;
		}
		if(n >= node->data) {
			insertElement(node->right, n);
		}
		if(n < node->data) {
			insertElement(node->left, n);
		}
	}
	void insert(int n) {
		insertElement(root, n);
	}
};
/* Return True if Node n exist in the Binary Search 
	Tree. */
bool existNode(Node *root, Node *n) {
    if(root == NULL) return false;
    if(root->data == n->data) return true;

    if(n->data > root->data) {
        if(existNode(root->right, n)) return true;
    }
    if(n->data < root->data) {
        if(existNode(root->left, n)) return true;
    }
    return false;
}

/* Inorder Traversal */
void inorden(Node* root) {
	if(!root) return;
  	inorden(root->left);
  	cout << root->data << " ";
  	inorden(root->right);
}

int main() {
	BST *Tree = new BST();
	
	int array[] = {4, 5, 9, 11, 6, 6};
	/* Building BST */
	for(int i = 0; i < 5; i++) {
		Tree->insert(array[i]);
	}
	cout << "Print BST Inorden: " << endl;
	inorden(Tree->root);
	cout << endl << endl;

	Node *aux = new Node(0);
	if(existNode(Tree->root, aux)) {
		cout << "Node with value:" << aux->data << " exist" << endl;
	} else cout << "Node with value:" << aux->data << " doesnt exist" << endl;

}