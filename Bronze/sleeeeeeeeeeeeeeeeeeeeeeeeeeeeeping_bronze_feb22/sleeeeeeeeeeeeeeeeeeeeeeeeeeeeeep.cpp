#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> vals(n);
		int total = 0;
		for(int i = 0; i < n; ++i){
			cin >> vals[i];
			total += vals[i];
		}
		if(!total){
			cout << 0 << endl;
			continue;
		}
		for(int factor = 1; factor <= total; ++factor){
			if(total % factor){
				continue;
			}else{
				int sum = 0;
				bool works = true;
				for(int i = 0; i < n; ++i){
					sum += vals[i];
					if(sum == factor){
						sum = 0;
					}
					if(sum > factor){
						works = false;
						break;
					}
				}
				if(works){
					cout << n - total / factor << endl;
					break;
				}
			}
		}
	}
}
