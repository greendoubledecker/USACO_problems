#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		unordered_map<int, int> heights;
		int tallest = 0;
		int n;
		cin >> n;
		for(int j = 0; j < n; ++j){
			int m;
			cin >> m;
			++heights[m];
			if(tallest < m){
				tallest = m;
			}
		}
		int ans = 1;
		for(int j = 1; j < tallest; ++j){
			if(heights[j] >= 2){
				ans += 2;
			}
		}
		cout << ans << endl;
	}
}
