/* Abigail Nicolas Sayago.
	This is a basic implementation of a trie structure,
*/
#include<bits/stdc++.h>
#define MAX 26
using namespace std;
struct TrieNode {
	map<char, TrieNode *> children; // Reference to the next character
	int freq;		    // frequency of a string
	TrieNode() { 		// Constructor
		freq = 0;	    // In the beginning, node is not a end of string
	}
};
/* Description: Insert a string into structure, if the string
				already exist, frequency is incremented.
   Return: Nothing, trie is modified. 							*/
void insert(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) {
			current->children[target[i]] = new TrieNode();
		}
		current = current->children[target[i]];
	}
	current->freq++;
}
/* Description: Search a string.
   Return: True if string exist, otherwise false. 		   		*/
bool exist(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) return false;
		current = current->children[target[i]];
	}
	return current && current->freq; 
}
/* Description: Recursive function that save all the strings saved.
   Return: Nothing, a vector of ans is passed by reference.    		*/
void getWords(TrieNode *root, vector<pair<string, int>> &ans, string word) {
	if(!root) return;
	TrieNode *current = root;
	if(current->freq) ans.push_back(make_pair(word, current->freq));
	for(auto &i: current->children) {
		getWords(i.second, ans, word + i.first);
	}
}
/* Return a vector of pairs with string and int are elements.
   the second element, represent frequency of string. */
vector<pair<string, int>> getWords(TrieNode *root) {
	vector<pair<string, int>> ans;
	getWords(root, ans, "");
	return ans;
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
	vector<pair<string, int>> aux = getWords(root);
	cout << "Diccionario" << endl;
	for(int i = 0; i < aux.size(); i++) {
		cout << aux[i].first << " " << aux[i].second << endl;
	} cout << endl;
}