#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void bubbleSort(vector<int> &v) { // O(n^2)
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v.size()-1; j++) {			
			if(v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
			}
		}
	}
}

int main() {
	optimizar_io
	vector<int> a = {5, 6, 7, 1, 4, 3, 3, 5};
	bubbleSort(a);
	fore(i, 0, a.size()) cout << a[i] << " ";
	cout << endl;
}
