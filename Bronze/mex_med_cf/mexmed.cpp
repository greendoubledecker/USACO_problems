#include <iostream> // slow, will TLE
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
		for(int r = l + 1; r <= num; ++r){
			vector<int> subset(permutation.begin() + l, permutation.begin() + r);
			sort(subset.begin(), subset.end());
			bool success = true;
			double middle = (r - l)/2.0;
			for(int i = 0; i < middle; ++i){
				//cout << "x" << endl;
				if(subset[i] != i){
					success = false;
					break;
				}
			}
			//cout << "Subset: ";
			//cout << endl << "success = " << success << endl;
			if(success){
				ans++;
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
