#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct UnionFind {
	int n;
	vector<int> id, size;

	UnionFind(int N) : n(N), id(N), size(N, 1) { // O(N)
		for(int i = 1; i <= n; i++) {
			id[i] = i;
		}
	}
	int find(int i) { // O(log*N)
		while(i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	void join(int i, int j) { //O(log*N)
		i = find(i), j = find(j);
		if(i == j) return;
		if(size[i] < size[j]) { // Choosing by weidth
			std::swap(i, j);
		}
		n--; 
		id[j] = i;
		size[i] += size[j];
	}
	bool connected(int i, int j) { // O(log*N)
		return find(i) == find(j);
	}
	int numberSets() {
		return n;
	}
};


int main() {
	int n = 10;
	UnionFind *uf = new UnionFind(n);

	uf->join(1, 2);
	cout << uf->numberSets() << endl;
	uf->join(5, 6);
	cout << uf->numberSets() << endl;
	uf->join(10, 7);
	cout << uf->numberSets() << endl;
	uf->join(10, 6);
	cout << uf->numberSets() << endl;
}