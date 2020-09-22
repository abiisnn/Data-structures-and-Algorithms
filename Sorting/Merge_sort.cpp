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

// temp = []
// v= [3 4 6 1 2 3] => firstPart[3 4 6], secondPart[1,2,3]
void merge(vector<int> &v, int left, int right) {
	vector<int> temp(right - left + 1);

	int middle = (left + right) / 2;
	int firstPart = left;
	int secondPart = 1 + middle;
	int indTemp = 0;
	while(firstPart <= middle && secondPart <= right) {
		if(v[firstPart] <= v[secondPart]) {
			temp[indTemp] = v[firstPart];
			firstPart++;
		} else {
			temp[indTemp] = v[secondPart];
			secondPart++;
		}
		indTemp++;
	}
	while(firstPart <= middle) {
		temp[indTemp] = v[firstPart];
		firstPart++;
		indTemp++;
	}
	while(secondPart <= right) {
		temp[indTemp] = v[secondPart];
		secondPart++;
		indTemp++;
	}
}
void mergeSort(vector<int> &v, int left, int right) {
	if(left >= right) return;
	int middle = (left + right) / 2;
	mergeSort(v, left, middle);
	mergeSort(v, middle + 1, right);
	merge(v, left, right);
}

int main() {
	optimizar_io
	vector<int> a = {5, 6, 7, 1, 4, 3, 3, 5};
	mergeSort(a, 0, a.size()-1); //[0, 5]
	for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl;
}
