#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> x(1, 0);
	for(int i = 0; i < n; ++i){
		int e;
		cin >> e;
		x.push_back(e);
	}
	x.push_back(1001);
	int maxx = 0;
	int cur = 1;
	for(int i = 1; i < x.size(); ++i){
		if(x[i] == x[i-1] + 1){
			++cur;
		}else{
			maxx = max(maxx, cur);
			cur = 1;
		}
	}
	maxx = max(maxx, cur);
	cout<<max(maxx - 2, 0) << endl;
}
