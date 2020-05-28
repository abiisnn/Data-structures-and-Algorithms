#include<bits/stdc++.h>
using namespace std;

#define MAX 26
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
void insert(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		int pos = target[i] - 'a';
		if(current->children[pos] == NULL) {
			current->children[pos] = new TrieNode();
		}
		current = current->children[pos];
	}
	current->isEnd = true;
	current->frec++;
}
bool exist(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		int pos = target[i] - 'a';
		if(!current->children[pos]) return false;
		current = current->children[pos];
	}
	return current && current->isEnd;
}

void getWords(TrieNode *root, vector<pair<string, int>> &ans, string word) {
	TrieNode *current = root;
	for(int i = 0; i < MAX; i++) {
		if(current->children[i]) {
			if(current->children[i]->isEnd) 
				ans.push_back(make_pair(word + char(i+'a'), current->children[i]->frec));
			getWords(current->children[i], ans, word + char(i+'a'));
		}
	}
}
int main() {
	TrieNode *root = new TrieNode();
	vector<string> a = {"hola", "bye", "abigail", "sergio", "abimael", "serpentina", "abigail"};
	vector<string> b = {"a", "bye", "abigail", "g"};
	for(int i = 0; i < a.size(); i++) {
		insert(root, a[i]);
	}
	for(int i = 0; i < b.size(); i++) {
		cout << b[i] << " " << exist(root, b[i]) << endl;
	}
	vector<pair<string, int>> aux;
	getWords(root, aux, "");
	cout << "Diccionario" << endl;
	for(int i = 0; i < aux.size(); i++) {
		cout << aux[i].first << " " << aux[i].second << endl;
	} cout << endl;
}