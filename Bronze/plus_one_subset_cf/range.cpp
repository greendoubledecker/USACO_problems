#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int maxx = -1, minn = 1000'000'000;
		while(n--){
			int sdkj;
			cin >> sdkj;
			maxx = max(maxx, sdkj);
			minn = min(minn, sdkj);
		}
		cout << maxx - minn << endl;
	}
}
