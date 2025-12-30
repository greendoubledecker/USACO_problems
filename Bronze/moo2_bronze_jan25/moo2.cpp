#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> input(n);
	vector<int> num(n); //num[x] is the number of times x appears
	vector<int> befCnt(1, 0); //number of distinct integers that appear before position i
	vector<vector<int>> indices(n);
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		--a;
		++num[a];
		indices[a].push_back(i);
		if(num[a] == 1){
			befCnt.push_back(befCnt[i] + 1);
		}else{
			befCnt.push_back(befCnt[i]);
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		cout << befCnt[i] << endl;
	}
	*/
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		if(num[i] >= 2){
			//cout << i + 1 << " appears " << num[i] << " times and the second-last is " << indices[i][num[i] - 2] << ". There are " << befCnt[indices[i][indices[i].size() - 2]] << " distinct integers before that appearance." << endl;
			ans += befCnt[indices[i][num[i] - 2]];
			if(num[i] > 2){
				--ans;
			}
		}
	}
	cout << ans << endl;
}
