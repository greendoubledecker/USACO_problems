#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		vector<long long> v(n);
		long long maxx = -1'000'000'000'000'000'000;
		long long maxDiff = 0;
		for(long long i = 0; i < n; ++i){
			long long a;
			cin >> a;
			maxx = max(maxx, a);
			maxDiff = max(maxDiff, maxx - a);
		}
		if(maxDiff == 0){
			cout << 0 << endl;
		}
		for(long long i = 60; i >= 0; --i){
			if(maxDiff >> i){
				cout << i + 1 << endl;
				break;
			}
		}
	}
}
