#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		vector<int> a(n);
		iota(a.begin(), a.end(), 1);
		int l = 0;
		int r = n - 1;
		for(; l < r; ++l){
			int diff = (r - l) * 2;
			if(k >= diff){
				k -= diff;
				swap(a[l], a[r]);
				--r;
			}
		}
		if(k){
			cout << "no" << endl;
		}else{
			cout << "yes" << endl;
			for(int i = 0; i < n; ++i){
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}
