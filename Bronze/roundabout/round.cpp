#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int intersect(int l1, int u1, int l2, int u2){
	int lower = max(l1, l2);
	int upper = min(u1, u2);
	return max(0, upper - lower + 1);
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		int lower = 5, upper = 49, ans = 0, pow = 1;
		while(pow < 100000000){
			pow *= 10;
			lower += 4 * pow;
			upper = 5 * pow - 1;
			ans += intersect(lower, upper, 2, n);
		}
		cout << ans << endl;
	}
	return 0;
}
