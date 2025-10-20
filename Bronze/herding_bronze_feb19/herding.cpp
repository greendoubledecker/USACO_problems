#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> cows;
	for(int i = 0; i < 3; ++i){
		int cow;
		cin >> cow;
		cows.push_back(cow);
	}
	sort(cows.begin(), cows.end());
	if(cows[0] + 1 == cows[1] && cows[1] + 1 == cows[2]){
		cout << 0 << endl;
	}else if(cows[0] + 2 == cows[1] || cows[1] + 2 == cows[2]){
		cout << 1 << endl;
	}else{
		cout << 2 << endl;
	}
	int maxdist = max(cows[1] - cows[0], cows[2] - cows[1]);
	cout << maxdist - 1 << endl;
	return 0;
}
