#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		//cout << "n is " << n << endl;
		vector<int> ps(1, 0);
		for(int j = 0; j < n; ++j){
			//cout << "inner" << endl;
			char c;
			cin >> c;
			ps.push_back(ps[j] + (c - '0') - 1);
		}
		
		unordered_map<int, int> count;
		//count[0] = 1;
		for(int sum : ps){
			++count[sum];
			//cout << "incremented " << sum << "." << endl;
		}
		
		unsigned long long ans = 0;
		for(const auto& pair : count){
			if(pair.second > 1){
				unsigned long long num = static_cast<unsigned long long>(pair.second) * (pair.second - 1);
				ans += num / 2;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
