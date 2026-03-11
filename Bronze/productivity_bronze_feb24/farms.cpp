#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	vector<int> diff;
	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		diff.push_back(c[i] - t);
	}
	int cnt[1'000'010];
	for(int i = 0; i < n; ++i){
		++cnt[max(diff[i], 0)];
	}
	int ps[1'000'010];
	int sum = 0;
	for(int i = 0; i < 1'000'010; ++i){
		sum += cnt[i];
		ps[i] = sum;
	}
	while(q--){
		int v, s;
		cin >> v >> s;
		int open = n - ps[s];
		if(open >= v){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
