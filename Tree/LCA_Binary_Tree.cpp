#include <bits/stdc++.h>
using namespace std;

/* The tree node has data, left child and right child */
struct Node {
    Node* left, *right;
    int data;
    Node(int v, Node* l = NULL, Node* r = NULL) : data(v), left(l), right(r) {}
};
/* Return true if Node n exist in the Binary Tree and 
   save the path in the vector. */
bool getPath(Node *root, Node *n, vector<Node *> &path) {
    if(!root) return false; // if(root == NULL)
    if(root->data == n->data) {
        path.push_back(root);
        return true;
    }
    if(getPath(root->left, n, path) or getPath(root->right, n, path)) {
        path.push_back(root);
        return true;
    } 
  return false;
}
/* Return NULL if some path is empty, in other case 
   return the first Equal element in array a and b. */
Node* getFirstEqualElement(vector<Node *> &a, vector<Node *> &b) { // O(n * log(n))
    Node * ans = NULL;
    // set = [10, 9, 5]
    // [4, 3, 5]
    set<Node *> s;
    for(int i = 0; i < (int)a.size(); i++) {
        s.insert(a[i]);
    }
    for(int i = 0; i < (int)b.size(); i++) {
        if(s.count(b[i])) {
            ans = b[i];
            break;
        }
    }
    return ans;
}
/* Return LCA of a and b Node. */
Node* LCA(Node *root, Node *a, Node *b) {
    vector<Node *> pathA;
    vector<Node *> pathB;
    Node *ans = NULL;

    if(getPath(root, a, pathA) && getPath(root, b, pathB)){ 
        ans = getFirstEqualElement(pathA, pathB);
    } 
    return ans;
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

/*              5
            3       9
          1  4    8  10
*/
    Node *ans = LCA(root, nine, eight);
    if(ans) cout << ans->data << endl;
    else cout << "Some node doesnt exist" << endl;
}
