#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		int different = x ^ y;
		for(int i = 0; i < 32; ++i){
			int bit = different & (1 << i);
			if(bit){
				cout << bit << endl;
				break;
			}
		}
	}
}
