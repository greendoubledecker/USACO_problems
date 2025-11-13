#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	//freopen("outofplace.in", "r", stdin);
	//freopen("outofplace.out", "w", stdout);
	vector<int> current, correct;
	int num;
	cin >> num;
	for(int i = 0; i < num; ++i){
		int cow;
		cin >> cow;
		current.push_back(cow);
	}
	correct = current;
	sort(correct.begin(), correct.end());
	int ans = 0;
	for(int i = 0; i < num; ++i){
		if(current[i] != correct[i]){
			++ans;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
