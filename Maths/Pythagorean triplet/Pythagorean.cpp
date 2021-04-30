#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int main() {
	int s = 100;
	for(int a = 3; a <=(s-3); a++) {
		for(int b = (a+1); b <= s-1-a; b++) {
			int c = s-a-b;
			cout << c << endl;
			if((c*c) == (a*a + b*b)) {
				cout << a <<" "<<b<<" "<<c << endl;
			}
		}
	}
}