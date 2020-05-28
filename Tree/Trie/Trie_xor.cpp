/* Given an array, find the maximun XOR that can be
   formed by two elements in the array. 			*/
#include<bits/stdc++.h>
#define MAX 2
using namespace std;
typedef long long int lli;

int differents = 0;
void printBits(lli n) {
	for(int i = sizeof(n) * 8 - 1; ~i; i--) {
		cout << ((n >> i) & 1) << " ";
	}
	cout << endl;
}
struct TrieNode {
	TrieNode *children[MAX];
	bool isEnd;
	TrieNode() {
		isEnd = false;
		for(int i = 0; i < MAX; i++) children[i] = NULL; 
	}
};
void insert(TrieNode *root, lli n) {
	TrieNode *current = root;
	for(int i = sizeof(n) * 8 - 1; ~i; i--) {
		lli pos = (n >> i) & 1ll;
		if(!current->children[pos]) {
			current->children[pos] = new TrieNode();
		}
		current = current->children[pos];
	}
	current->isEnd = true;
}
lli bestXOR(TrieNode *root, lli n) {
	TrieNode *current = root;
	lli ans = 0;
	for(int i = sizeof(n) * 8 - 1; ~i; i--) {
		lli pos = (n >> i) & 1ll;
		if(current->children[!pos]) pos = !pos;
		if(pos) ans = ans | (1ll << i);
		current = current->children[pos];	
	}
	return ans;
}
int main() {
	int n; cin >> n;
	TrieNode *root = new TrieNode();
	vector<lli> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		insert(root, v[i]);
	}
	lli bestAns = 0;
	for(int i = 0; i < n; i++) {
		lli aux = bestXOR(root, v[i]);
		if((v[i] xor aux) > bestAns) bestAns = v[i] xor aux;
	}
	cout << bestAns << endl;
}