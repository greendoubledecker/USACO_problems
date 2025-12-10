#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n;
	cin >> n;
	vector<long long> sums(1, 0);
	for(int i = 1; i < n + 1; ++i){
		int c;
		cin >> c;
		sums.push_back(sums[i - 1] + c);
	}
	int maxSize = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			if((sums[j + 1] - sums[i]) % 7 == 0){
				if(maxSize < j - i + 1) maxSize = j - i + 1;
			}
		}
	}
	cout << maxSize << endl;
	return 0;
}
