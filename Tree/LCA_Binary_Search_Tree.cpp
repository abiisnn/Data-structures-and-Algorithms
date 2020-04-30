#include <bits/stdc++.h>
using namespace std;

/* The tree node has data, left child and right child */
struct Node {
    Node* left, *right;
    int data;
    Node(int v, Node* l = NULL, Node* r = NULL) : data(v), left(l), right(r) {}
};

/* Return true if some children of root has the 
   same value than n Node. */
bool specialCase(Node *root, Node *n) {
    if(!root) return false;
    if(root->left) {
        if(root->left == n) 
            return true;
    }
    if(root->right) {
        if(root->right == n) 
            return true;
    }
    return false;
}
/* WARNING: n1 and n2 has to exist in the tree.
   Return LCA of n1 and n2. */
Node *LCAfunc(Node *root,  Node *n1,  Node *n2) {
    if(root == NULL) return NULL;
 
    if(root == n1) {
        if(specialCase(root, n2)) 
            return root;
    }
    if(root == n2) {
        if(specialCase(root, n1)) 
            return root;
    }
    if(n1->data < root->data && n2->data < root->data) {
        return LCAfunc(root->left, n1, n2);
    }
    if(n1->data > root->data && n2->data > root->data) {
        return LCAfunc(root->right, n1, n2);
    }
    return root;
}
/* Return true if Node n exist in the BST */
bool exist(Node *root, Node *n) {
    if(root == NULL) return false;
    if(root == n) return true;

    if(n->data > root->data) {
        if(exist(root->right, n)) return true;
    }
    if(n->data < root->data) {
        if(exist(root->left, n)) return true;
    }
    return false;
}
/* Return NULL if n1 or n2 doesnt exist, in other case
   return LCA of Nodes n1 and n2. */
Node *lca(Node *root, Node *n1, Node *n2) {
	if(root == NULL) return NULL;
    if((exist(root, n1) && exist(root, n2))) return LCAfunc(root, n1, n2);
    return NULL;
}

int main() {
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    Node *seven = new Node(7);
    Node *eight = new Node(8);
    Node *nine = new Node(9);
    Node *ten = new Node(10);
    Node *eleven = new Node(11);

    three->left = one;
    three->right = four;
    nine->left = eight;
    nine->right = ten;

    five->left = three;
    five->right = nine;
    Node * root = five;

 /*             5
            3     9
          1  4   8  10
*/
    Node *ans = lca(root, five, ten);
    if(ans) cout << ans->data << endl;
    else cout << "Some node doesnt exist" << endl;
}