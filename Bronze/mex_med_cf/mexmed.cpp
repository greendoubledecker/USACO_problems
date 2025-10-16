#include <iostream> // slow, will TLE
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

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
	if(permutation.size() == 1){
		cout << 1 << endl;
		return;
	}
	int ans = 0;
	for(int l = 0; l < num; ++l){
		for(int r = l + 1; r < num; ++r){
			set<int> subset;
			for(int i = l; i <= r; ++i){
				subset.insert(permutation[i]);
			}
			int middle = (r - l)/2;
			auto it = subset.begin();
			advance(it, middle);
			cout << "l " << l << " r " << r << " middle " << middle << " element at middle " << *it << endl;
			if(*it == middle){
				++ans;
			}
			//cout << "Subset: ";
			//cout << endl << "success = " << success << endl;
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
