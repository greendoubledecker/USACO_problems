#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 15;
	for(int i = 0; i < 4; ++i){
		int d;
		cin >> d;
		n -= d;
	}
	cout << n << endl;
}
