#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc(){
	int num;
	cin >> num;
	vector<int> permutation;
	for(int i = 0; i < num; ++i){
		int value;
		cin >> value;
		permutation.push_back(value);
	}
	int ans = 0;
	for(int l = 0; l < num; ++l){
		vector<int> subset;
		for(int r = l; r < num; ++r){
			auto insertPos = lower_bound(subset.begin(), subset.end(), permutation[r]);
			subset.insert(insertPos, permutation[r]);
			int middle = (r - l)/2;
			if(subset[middle] == middle){
				++ans;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i){
		tc();
	}
	return 0;
}
