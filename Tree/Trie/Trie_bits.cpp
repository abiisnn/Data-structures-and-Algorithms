#include<bits/stdc++.h>
#define MAX 2
using namespace std;

int differents = 0;
struct TrieNode {
	TrieNode *children[MAX];
	int frec = 0;
	bool isEnd;
	TrieNode() {
		isEnd = false;
		for(int i = 0; i < MAX; i++) children[i] = NULL; 
	}
};
void insert(TrieNode *root, int n) {
	TrieNode *current = root;
	for (int i = sizeof(n) * 8 - 1; ~i; i--) {
		int pos = (n >> i) & 1;
		if(!current->children[pos]) {
			current->children[pos] = new TrieNode();
		}
		current = current->children[pos];
	}
	current->isEnd = true;
	current->frec++;
}
bool exist(TrieNode *root, int n) {
	TrieNode *current = root;
	for (int i = sizeof(n) * 8 - 1; ~i; i--) {
		int pos = (n >> i) & 1;
		if(!current->children[pos]) return false;
		current = current->children[pos];
	}
	return current && current->isEnd;
}
void getNumbers(TrieNode *root, vector<pair<int, int>> &ans, int n, int k) {
	TrieNode *current = root;
	for(int i = 0; i < MAX; i++) {
		if(current->children[i]) {
			int aux = n, kaux = k;
			if(i) aux = n | (1 << kaux);
			kaux--;
			if(current->children[i]->isEnd) {
				ans.push_back(make_pair(aux, current->children[i]->frec));
			}
			getNumbers(current->children[i], ans, aux, kaux);
		}
	}
}
int main() {
	int n, m; cin >> n >> m;
	vector<int> v(n), q(m);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < m; i++) cin >> q[i];

	TrieNode *root = new TrieNode();
	for(int i = 0; i < v.size(); i++) {
		insert(root, v[i]);
	}
	for(int i = 0; i < q.size(); i++) {
		cout << q[i] << " " << exist(root, q[i]) << endl;
	}
	vector<pair<int, int>> aux;
	int k = sizeof(n) * 8 - 1;
	cout << "---------" << endl;
	getNumbers(root, aux, 0, k);

	cout << "Diccionario" << endl;
	for(int i = 0; i < aux.size(); i++) {
		cout << aux[i].first << " " << aux[i].second << endl;
	} cout << endl;
}