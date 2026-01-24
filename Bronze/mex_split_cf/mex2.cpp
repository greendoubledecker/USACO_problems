#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int totalMex = 0;
		set<int> seen;
		for(int i = 0; i < n; ++i){
			seen.insert(a[i]);
		}
		for(int i = 0; i <= n; ++i){
			if(!seen.count(i)){
				totalMex = i;
				break;
			}
		}
		
		set<int> nums;
		int mex = 0;
		int split;
		for(int i = 0; i < n; ++i){
			nums.insert(a[i]);
			if(a[i] == mex){
				for(int j = mex + 1; j <= n; ++j){
					if(!nums.count(j)){
						mex = j;
						break;
					}
				}
			}
			if(mex == totalMex){
				split = i; //include split in first group
				break;
			}
		}
		
		int restMex;
		set<int> other;
		for(int i = split + 1; i < n; ++i){
			other.insert(a[i]);
		}
		for(int i = 0; i <= n; ++i){
			if(!other.count(i)){
				restMex = i;
				break;
			}
		}
		//cout << "total = " << totalMex << " first = " << mex << " last = " << restMex << "split at " << split << endl;
		
		if(restMex != totalMex){
			cout << -1 << endl;
		}else{
			cout << "2" << endl << "1 " << split + 1 << endl << split + 2 << " " << n << endl;
		}
	}
}
