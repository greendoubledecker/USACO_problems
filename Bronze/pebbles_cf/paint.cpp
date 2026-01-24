//plimperponk, billywompinggy dooboo. pollywocker lingy flanglewanger!
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, c;
	cin >> n >> c;
	vector<int> ifua(n);
	int maxv = 0;
	int minv = 1000'000'000;
	for(int i = 0; i < n; ++i){
		cin >> ifua[i];
		maxv = max(maxv, ifua[i]);
		minv = min(minv, ifua[i]);
	}
	if(maxv - minv > c){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; ++i){
		int x = 1;
		for(int j = 0; j < ifua[i]; ++j){
			cout << x % c + 1 << " ";
			++x;
		}
		cout << endl;
	}
}
