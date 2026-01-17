#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		--b;
		--c;
		vector<int> num;
		if(a == 1234){
			num = {1,2,3,4};
		}else if(a == 123){
			num = {1,2,3};
		}else{
			num = {1,2};
		}
		vector<int> j = num;
		while(b--){
			next_permutation(j.begin(), j.end());	
		}
		vector<int> k = num;
		while(c--){
			next_permutation(k.begin(), k.end());	
		}
		int ans = 0;
		for(int i = 0; i < num.size(); ++i){
			if(j[i] == k[i]){
				++ans;
			}
		}
		cout << ans << "A" << num.size() - ans << "B" << endl;
	}
}
