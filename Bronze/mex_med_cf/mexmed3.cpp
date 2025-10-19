#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

void tc(){
	int num;
	cin >> num;
	if(num == 1){
		cout << 1 << endl;
		return;
	}
	vector<int> permutation;
	for(int i = 0; i < num; ++i){
		int value;
		cin >> value;
		permutation.push_back(value);
	}
	int ans = 0;
	for(int l = 0; l < num; ++l){
		set<int> subset;
		for(int r = l; r < num; ++r){
			subset.insert(permutation[r]);
			int middle = (r - l)/2;
			auto it = subset.begin();
			advance(it, middle);
			if(*it == middle){
				++ans;
			}
		}
	}
	//++ans;
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
