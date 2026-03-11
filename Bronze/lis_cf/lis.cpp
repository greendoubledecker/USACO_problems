#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		vector<int> v;
		cin >> n;
		for(int i = 0; i < n; ++i){
			int g;
			cin >> g;
			v.push_back(g);
		}
		int s = 0;
		int d = 0;
		map<int, int> count;
		for(int i = 0; i < n; ++i){
			int a = v[i];
			++count[a];
			if(count[a] == 2){
				++d;
			}
		}
		for(auto&p : count){
			if(p.second == 1){
				++s;
			}
		}
		cout << d + (s + 1) / 2 << endl;
	}	
}
